//APPROACH -1
//T.C : O(g+w+g×max(n,m)+n×m)
//S.C : O(n*m)
class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(auto i:guards){
            vis[i[0]][i[1]]=3;
        }
        for(auto i:walls){
            vis[i[0]][i[1]]=2;
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(auto i:guards){
            int row=i[0],col=i[1];
            for(int k=0; k<4; k++){
                int nrow=row,ncol=col;
                while(1){
                    nrow+=delrow[k];
                    ncol+=delcol[k];
                    if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || vis[nrow][ncol]==3 || vis[nrow][ncol]==2) break;
                    vis[nrow][ncol]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};

//APPROACH -2 UNION FIND
//T.C : O(g*max(n,m))
//S.C : O(n*m)
// union find class with Size & components
class UnionFind {
    int root[100001], Size[100001];
public:
    int components;
    //Constructor using initializer list
    UnionFind(int n): components(n+1){
        fill(Size, Size+n+1, 1);
        iota(root, root+n+1, 0);//[0,1,...,n]    
    }
    
    int Find(int x) {//Path Compression O(alpha(n))
        if (x==root[x]) 
            return x;
        return root[x] = Find(root[x]);
    }

    bool Union(int x, int y) { //Union by Size O(alpha(n))   
        x=Find(x), y=Find(y);
        
        if (x == y) return 0;
        
        if (Size[x] > Size[y]) {
            Size[x] +=Size[y];
            root[y] = x;
        } 
        else {
            Size[y] += Size[x];
            root[x] = y;
        }       
        components--;
        return 1;
    }     
};

class Solution {
public:
    bitset<100000> grid=0;
    int m, n, N;
    inline int  idx(int r, int c){
        return r*n+c;
    }
    void cross(int r, int c, UnionFind& G) {
        // downwards
        for (int i = r + 1; i < m; i++) {
            if (grid[idx(i, c)]) break;
            G.Union(idx(i, c), N); // connect to N
        }
        // upwards
        for (int i = r - 1; i >= 0; i--) {
            if (grid[idx(i, c)]) break;
            G.Union(idx(i, c), N); // connect to N
        }
        // rightwards
        for (int j = c + 1; j < n; j++) {
            if (grid[idx(r, j)]) break;
            G.Union(idx(r, j), N); // connect to N
        }
        // leftwards
        for (int j = c - 1; j >= 0; j--) {
            if (grid[idx(r, j)]) break;
            G.Union(idx(r, j), N); // connect to N
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        this->m = m, this->n = n;
        N=n*m;
        UnionFind G(N);

        // Mark walls
        for (auto& ij : walls){
            int r = ij[0], c = ij[1];
            grid[idx(r, c)] = 1;
            G.components--;
        }
        // Mark guards 
        for (auto& ij : guards){
            int r = ij[0], c = ij[1];
            grid[idx(r, c)] = 1;
            G.components--;
        }
        // connect guarded Cells to N
        for (auto& ij : guards) {
            int r = ij[0], c = ij[1];
            cross(r, c, G);
        }
        return G.components-1;
    }
};

