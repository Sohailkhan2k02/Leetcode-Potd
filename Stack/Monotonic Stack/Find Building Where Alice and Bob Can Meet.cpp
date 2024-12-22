//T.C : O(queries.size()) + O(n) + O(queries.size() * log(n))
//S.C : O(n + queries.size())
class Solution {
public:
    int bSearch(int height,vector<pair<int,int>>&st, int n){
        int l=0,h=st.size()-1,res=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(st[m].first>height){
                res=m;
                l=m+1;
            }
            else h=m-1;
        }
        return res;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        vector<int>res(queries.size(),-1);
        vector<pair<int,int>>st;
        vector<vector<pair<int,int>>>restQueries(n);
        for(int i=0; i<queries.size(); i++){
            int u=queries[i][0],v=queries[i][1];
            if(u>v) swap(u,v);
            if(heights[u]<heights[v] || u==v){
                res[i]=v;
            }
            if(res[i]==-1) restQueries[v].push_back({heights[u],i});
        }
        for(int i=n-1; i>=0; i--){
            for(auto& [h,ind]:restQueries[i]){
                int pos=bSearch(h,st,n);
                if(pos!=-1) res[ind]=st[pos].second;
            }
            while(!st.empty() && st.back().first<=heights[i]){
                st.pop_back();
            }
            st.push_back({heights[i],i});
        }
        return res;
    }
};
