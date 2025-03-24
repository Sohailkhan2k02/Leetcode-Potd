//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int countDays(int d, vector<vector<int>>& m) {
        vector<pair<int,int>>mpp;
        for(auto it:m){
            int u=it[0],v=it[1];
            mpp.push_back({it[0],1});
            mpp.push_back({it[1],-1});
        }
        mpp.push_back({0,0});
        mpp.push_back({d+1,0});
        sort(mpp.begin(),mpp.end());
        int sum=0,cnt=0;
        for(int i=0; i<mpp.size()-1; i++){
            sum+=mpp[i].second;
            if(sum==0){
                cnt+=max(mpp[i+1].first-mpp[i].first-1,0);
            }
        }
        return cnt;
    }
};
