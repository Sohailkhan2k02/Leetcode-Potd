class Solution {
public:
    static inline int MOD = int(1e9) + 7;
    int numOfSubarrays(vector<int>& arr) {
        const int n = arr.size();
        int odd = 0,even = 1,res = 0,sm = 0;
        for(int i = 0;i < n;i++){
            sm += arr[i];
            if(sm & 1){
                ++odd;
                res = (res + even) % MOD;
            }
            else{
                ++even;
                res = (res + odd) % MOD;
            }
        }
        return res;
    }
};
