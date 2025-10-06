class Solution {
public:
vector<pair<int,int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
};
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         
         vector<vector<int>>res(m,vector<int>(n,INT_MAX));
         if(m==0 || n==0) return 0;

        using Node=pair<int,pair<int,int>>;
        priority_queue<Node,vector<Node>,greater<Node>>pq;


        auto issafe=[&](int x,int y){
            return x>=0 && x<m && y>=0 && y<n;
        };

      pq.push({grid[0][0],{0,0}});
      res[0][0]=grid[0][0];
      while(!pq.empty()){
        int d=pq.top().first;
        pair<int,int>node=pq.top().second;
        int x=node.first;
        int y=node.second;
           if (x==m-1 && y==n-1) return d;
        pq.pop();
        for(auto dir :directions){
            int x_=x+dir.first;
            int y_=y+dir.second;
            if(issafe(x_,y_)){
                int t=max(d,grid[x_][y_]);
                if(t<res[x_][y_]){
                    res[x_][y_]=t;
                    pq.push({t,{x_,y_}});
                }
            }   
        }
      }

       if(res[m-1][n-1]==INT_MAX) return 0;
       else return res[m-1][n-1]; 
      


    }
};
