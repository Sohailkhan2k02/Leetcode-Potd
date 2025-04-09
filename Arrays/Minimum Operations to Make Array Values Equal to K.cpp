//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int m = *min_element(nums.begin(), nums.end());
        if(m < k) return -1;
        if(m==k) return st.size()-1;
        return st.size();
    }
};
