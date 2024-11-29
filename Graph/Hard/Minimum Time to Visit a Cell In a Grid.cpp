//T.C : O(n*m(log(n*m))
//S.C : O(n*m)
class Solution {
public:
    using ll=long long;
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[1][0]>1 && grid[0][1]>1) return -1;
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
        vector<vector<ll>>dis(n,vector<ll>(m,INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            int t=pq.top().first;
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
                    int w=0;
                    if(!((grid[nrow][ncol]-t)&1)){
                        w=1;
                    }
                    ll nt=max(t+1,grid[nrow][ncol]+w);
                    if(dis[nrow][ncol]>nt){
                        dis[nrow][ncol]=nt;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
