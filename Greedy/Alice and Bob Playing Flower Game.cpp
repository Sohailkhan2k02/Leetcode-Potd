class Solution {
public:
    long long flowerGame(int n, int m) {
        long long maxi=max(n,m);
        long long mini=min(n,m);
        return (maxi*mini)/2;
    }
};
