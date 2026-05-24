class Solution {
    vector<int> dp;

    int dfs(vector<int>& arr, int d, int i) {
        if(dp[i] != -1) return dp[i];

        int n = arr.size(), ans = 1;

        // move right
        for(int j = i + 1; j <= min(n - 1, i + d); j++){
            if (arr[j] >= arr[i]) break;
            ans = max(ans, 1 + dfs(arr, d, j));
        }

        // move left
        for(int j = i - 1; j >= max(0, i - d); j--){
            if (arr[j] >= arr[i]) break;
            ans = max(ans, 1 + dfs(arr, d, j));
        }

        return dp[i] = ans;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size(), res = 1;
        dp.assign(n, -1);

        for(int i = 0; i < n; i++)
            res = max(res, dfs(arr, d, i));

        return res;
    }
};
