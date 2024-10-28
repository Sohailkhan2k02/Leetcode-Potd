//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        set<int> s;
        for(auto x: nums) s.insert(x);
        for(int i=n-1;i>0;i--) {
            double cur = nums[i];
            double sqr = sqrt(cur);
            int count = 1;
            while((int) sqr == sqr && s.count(sqr) > 0) {
                count++;
                cur = sqr;
                sqr = sqrt(cur);
            }
            if(count!=1) ans = max(ans, count);
        }
        if(ans == 0) return -1;
        return ans;
    }
};
