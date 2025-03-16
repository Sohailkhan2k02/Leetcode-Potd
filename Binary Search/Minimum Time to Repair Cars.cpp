//T.C : O(nlogt)
//S.C : O(1)
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        
        auto canRepair = [&](long long time) {
            long long repaired = 0;
            for (int r : ranks) {
                repaired += (long long)sqrt(time / r);
                if (repaired >= cars) return true;
            }
            return false;
        };
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canRepair(mid)) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};
