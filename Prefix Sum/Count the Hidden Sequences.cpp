//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long sum = 0, mini = 0, maxi = 0;
        for(int i:differences){
            sum += i;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        return max(0L, upper - maxi - lower + mini + 1);
    }
};
