//T.C : O(n+m)
//S.C : O(n+m)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int ptr1 = 0, ptr2 = 0;
        vector<vector<int>> res;

        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1][0] < nums2[ptr2][0]) {
                res.push_back(nums1[ptr1++]);
            }
            else if (nums1[ptr1][0] > nums2[ptr2][0]) {
                res.push_back(nums2[ptr2++]);
            }
            else res.push_back({nums1[ptr1][0], nums1[ptr1++][1] + nums2[ptr2++][1]});
        }

        // we still have some pairs left in nums1
        while (ptr1 < nums1.size()) {
            res.push_back(nums1[ptr1++]);
        }

        // we still have some pairs left in nums2
        while (ptr2 < nums2.size()) {
            res.push_back(nums2[ptr2++]);
        }

        return res;
    }
};
