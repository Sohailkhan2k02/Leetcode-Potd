class Solution {
public:
    using ll = long long;
    int maxRotateFunction(vector<int>& arr) {
        int n = arr.size();
        ll sum = 0, curr = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            curr += (i * 1ll * arr[i]);
        }

        ll mx = curr;
        for(int i=1; i<n; i++){
            curr = curr - ((n-1) * 1ll * arr[n-i]) + (sum - arr[n-i]);
            mx = max(mx, curr);
        }

        return (int)mx;
    }
};
