//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>mpp;
        for(auto i:intervals){
            int u=i[0],v=i[1];
            mpp[u]++;
            mpp[v+1]--;
        }

        int maxi=0,cnt=0;
        for(auto [u,f]:mpp){
            cnt+=f;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
