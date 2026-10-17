class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int x : nums) {
            arr.push_back({digitSum(x), x});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != arr[i].second) {
                int j = pos[arr[i].second];

                pos[nums[i]] = j;
                pos[nums[j]] = i;

                swap(nums[i], nums[j]);
                swaps++;
            }
        }

        return swaps;
    }
};
