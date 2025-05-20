//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        map<int,int>mpp;
        for(auto i:queries){
            mpp[i[0]]++;
            mpp[i[1]+1]--;
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=mpp[i];
            if(cnt<nums[i]) return false;
        }
        return true;
    }
};
