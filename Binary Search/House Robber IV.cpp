//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minCapability(vector<int>& nums, int k)
    {
        int n = nums.size();

        auto chk = [&](int c) -> bool
        {
            int cnt = 0;

            for (int i = 0; i < n; ++i)
            {
                if (nums[i] <= c)
                {
                    cnt++;
                    i++;
                }
            }

            return cnt >= k;
        };

        int l = 1, r = 1e9, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (chk(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return r + 1;
    }
};
