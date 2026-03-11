class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1 ; 
        int mask = (1 << (32 - __builtin_clz(n))) - 1; 
        return n ^ mask ;
    }
};
