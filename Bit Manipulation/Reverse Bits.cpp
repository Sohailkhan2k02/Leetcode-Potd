class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long rev=0;
        for(int i=0; i<32; i++){
            rev<<=1; // Shift left by 1 to make room for the next bit
            if(n&1){  // Check if the last bit of n is 1
                rev|=1;  // If yes, set the last bit of reversed to 1
            }
            n>>=1; // Shift right by 1 to get the next bit of n
        }
        return abs(rev);
    }
};
