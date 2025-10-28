#include <vector>
using namespace std;

class Solution {
public:
    bool simulate(const vector<int>& nums, int start, int dir) {
        int n = nums.size();
        vector<int> a = nums;
        int curr = start;
        while (curr >= 0 && curr < n) {
            if (a[curr] == 0) {
                curr += dir;
            } else {
                a[curr]--;
                dir = -dir;
                curr += dir;
            }
        }
        for (int v : a) if (v != 0) return false;
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) continue;  
            if (simulate(nums, i, -1)) ++ans; 
            if (simulate(nums, i, +1)) ++ans; 
        }
        return ans;
    }
};
