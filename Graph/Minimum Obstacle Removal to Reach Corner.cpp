//T.C : O(n*mLOG(n*m)) using dijstkra
//S.C : O(n*m)
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            int d=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1){
                return dis[i][j];
            }

            for(int k=0; k<4; k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(dis[nrow][ncol]>grid[i][j]+d){
                        dis[nrow][ncol]=grid[i][j]+d;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};

//APPROACH -2 
// USING 0-1 BFS
//T.C : O(N*M)
//S.C : O(N*M)
using int2 = pair<int, int>; // (dist, idx(i, j))
const static int d[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    inline static int idx(int i, int j, int m) {
        return i * m + j;
    }

    static int minimumObstacles(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size(), N=100000;
        unsigned dist[N];
        fill(dist, dist + n*m, INT_MAX);

        int2 q[N]; // circular deque
        int back = N/2, front = N/2; //Middle of array for space to prepend/append

        q[back++] = {0, 0}; // Start at (0, 0)
        dist[0] = 0;

        while (back != front) {
            auto [currD, ij] = q[front]; // Increment front with wrap-around
            front=(front==N-1)?0:front+1;
            auto [i, j] = div(ij, m);

            // Reach the target
            if (i == n - 1 && j == m - 1)
                return currD;

            // Explore all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                int nextD = currD + grid[r][s];
                int rs = idx(r, s, m);

                // Update if this path has a shorter distance
                if (nextD < dist[rs]) {
                    dist[rs] = nextD;
                    int2 next = {dist[rs], rs};

                    // Prepend or append based on weight
                    if (grid[r][s] == 0) {
                        front=(front==0)?N-1:front-1;
                        q[front] = next; // Prepend for weight 0
                    } 
                    else {
                        q[back] = next; // Append for weight 1
                        back=(back==N-1)?0:back+1;
                    }
                }
            }
        }
        return -1; // Never reach
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
