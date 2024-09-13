//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pre(n,0);
        pre[0]=arr[0];
        for(int i=1; i<n; i++){
            pre[i]=arr[i]^pre[i-1];
        }
        vector<int>res;
        for(auto it:queries){
            int u=it[0],v=it[1];
            if(u==0){
                res.push_back(pre[v]);
            }
            else{
                res.push_back(pre[v]^pre[u-1]);
            }
        }
        return res;
    }
};
