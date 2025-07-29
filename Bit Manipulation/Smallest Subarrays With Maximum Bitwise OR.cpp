class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int bitmask = 0;
        vector<int> last(32, -1); // Store last seen index for each bit

        for (int i = n - 1; i >= 0; i--) {
            bitmask |= nums[i];

            // Update last seen indices of bits
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                }
            }

            // Find how far we need to go to achieve all bits in bitmask
            int maxPos = i;
            for (int b = 0; b < 32; b++) {
                if (bitmask & (1 << b)) {
                    maxPos = max(maxPos, last[b]);
                }
            }

            result[i] = maxPos - i + 1;
        }

        return result;
    }
};
