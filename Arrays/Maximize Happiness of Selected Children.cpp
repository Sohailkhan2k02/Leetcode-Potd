class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        sort(arr.rbegin(), arr.rend());
        long long ans = 0;
        for(int i = 0; i < k; i++){
            ans += max(arr[i] - i, 0);
        }
        return ans;
    }
};
