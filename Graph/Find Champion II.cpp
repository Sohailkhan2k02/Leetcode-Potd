//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto i:edges){
            int u=i[0],v=i[1];
            indegree[v]++;
        }
        int cnt=0,res=-1;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                cnt++;
                res=i;
            }
        }
        if(cnt==1) return res;
        return -1;
    }
};
