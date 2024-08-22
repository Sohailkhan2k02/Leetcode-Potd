//Approach-1 (Using bit magic of XOR)
//T.C : O(log2(num))
//S.C : O(1)
class Solution {
public:
    int findComplement(int num) {
        int number_of_bits = (int)(log2(num)) + 1;
        
        for(int i = 0; i<number_of_bits; i++) {
            num = num^(1<<i); //Take Xor to flip
        }
        return num;
    }
};


//Approach-2 (Using XOR mask)
//T.C : O(log2(num))
//S.C : O(1)
class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        int number_of_bits = (int)(log2(num)) + 1;
        
        // Create a mask with all bits set to 1 that are of the same length as num
        unsigned int mask = (1U << numBits) - 1; //unsigned taken to avoid integer overflow

        // XOR num with mask to get the complement
        return num ^ mask;
    }
};


//Approach-3 (iterate digit by digit and create complement)
//T.C : O(log2(num))
//S.C : O(1)
class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;
        while (num) {
            // If the current bit is 0, set the corresponding bit in ans to 1
            if (!(num & 1))
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
};
