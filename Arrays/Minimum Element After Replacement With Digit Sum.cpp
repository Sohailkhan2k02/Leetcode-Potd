class Solution {
public:
    int f(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
    int minElement(vector<int>& nums) {
        for (auto& i : nums) {
        i = f(i);
    }
    return *min_element(nums.begin(), nums.end());
    }
};
