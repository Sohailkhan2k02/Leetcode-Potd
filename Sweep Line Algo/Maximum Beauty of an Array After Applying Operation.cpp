//T.C : O(n)
//S.C : O(max_element+2)
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int N = *max_element(nums.begin(), nums.end());
        vector<int> mpp(N + 2, 0);
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int u = max(nums[i] - k, 0);
            int v = min(nums[i] + k, N);
            mpp[u]++;
            mpp[v+1]--;
        }
        int res = 0,cnt = 0;
        for(auto &it:mpp){
            cnt+=it;
            res=max(res,cnt);
        }
        return res;
    }
};
