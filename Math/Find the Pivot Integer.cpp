// T.C: O(1)
// S.C: O(1)

class Solution {
public:
int pivotInteger(int n) {
        int sum = (n*(n+1))/2;
        int x = sqrt(sum);
        if(x*x == sum) return x;
        else return -1
}
};
