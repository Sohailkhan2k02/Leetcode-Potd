using ll = long long;
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<ll> st;
        ll n = nums.size();
        st.push(nums[0]);

        for (ll i = 1; i < n; i++) {
            ll g = __gcd((ll)nums[i], st.top());
            ll l = (nums[i] / g) * st.top(); 

            if (g > 1) {
                // keep merging while gcd > 1
                while (!st.empty() && __gcd(l, st.top()) > 1) {
                    ll g2 = __gcd(l, st.top());
                    l = (l / g2) * st.top();
                    st.pop();
                }
                st.push(l);
            } else {
                st.push(nums[i]);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
