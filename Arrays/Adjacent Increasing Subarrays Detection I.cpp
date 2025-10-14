using u32 = uint32_t;

class Solution
{
public:
    bool hasIncreasingSubarrays(std::vector<int>& nums, u32 k) noexcept
    {
        const u32 n = static_cast<u32>(nums.size());

        u32 i = 0, j = i + k, l = 0;
        int prev_i = -1, prev_j = -1;
        while (i != n - k && j != n && l != k)
        {
            int vi = nums[i], vj = nums[j];
            u32 b = vi <= prev_i || vj <= prev_j;
            l &= (b - 1) & l;
            ++i, ++j, ++l;
            prev_i = vi, prev_j = vj;
        }

        return l == k;
    }
};
