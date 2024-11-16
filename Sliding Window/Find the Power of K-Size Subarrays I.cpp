//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]+1){
                cnt++;
            }
            else cnt=1;
            if(i>=k-1){
                if(cnt>=k) res.push_back(nums[i]);
                else res.push_back(-1);
            }
        }
        return res;
    }
};
