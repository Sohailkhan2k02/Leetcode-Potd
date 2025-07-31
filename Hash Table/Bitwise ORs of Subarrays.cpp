class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> st;
        unordered_set<int> pre, curr;

        for (int i = 0; i < arr.size(); ++i) {
            for (auto it : pre) {
                st.insert(it | arr[i]);
                curr.insert(it | arr[i]);
            }

            st.insert(arr[i]);
            curr.insert(arr[i]);

            pre = curr;
            curr.clear();
        }

        return st.size();
    }
};
