//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int cnt=0;
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0; i<n; i++){
            for(auto j:mpp[nums[i]]){
                if((i*j)%k==0) cnt++;
            }
            mpp[nums[i]].push_back(i);
        }
        return cnt;
    }
};
