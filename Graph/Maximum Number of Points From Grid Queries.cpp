//T.C : O(n*mlog(n*m))
//S.C : O(n*m)
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size(),m=grid[0].size();
        int k=queries.size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<pair<int,int>>vc;
        vector<int>res(k,0);
        for(int i=0; i<k; i++){
            vc.push_back({queries[i],i});
        }
        sort(vc.begin(),vc.end());
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int cnt=0;
        for(auto &[v,i]:vc){
            while(!pq.empty() && pq.top().first<v){
                auto [val,cell]=pq.top();
                pq.pop();
                int x=cell.first,y=cell.second;
                cnt++;

                for(int d=0; d<4; d++){
                    int nrow=x+delrow[d],ncol=y+delcol[d];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                        pq.push({grid[nrow][ncol],{nrow,ncol}});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            res[i]=cnt;
        }
        return res;
    }
};
