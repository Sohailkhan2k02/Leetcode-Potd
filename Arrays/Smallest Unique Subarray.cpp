class Solution {
public:
    using ull = unsigned long long;
    bool check(int len, vector<int>& nums){
        int n = nums.size();

        unordered_map<ull,int>freq;

        const ull base = 131;

        ull h = 0;
        ull pow = 1;

        for(int i = 0; i<len; i++){
            h = h*base + nums[i];
            if(i+1 < len){
                pow *= base;
            }
        }

        freq[h]++;

        for(int i = len; i<n; i++){
            h -= pow*nums[i-len];
            h = h*base + nums[i];

            freq[h]++;
        }
        h = 0;

        for(int i = 0; i<len; i++){
            h = h*base + nums[i];
        }
        if(freq[h] == 1)return true;

        for(int i = len; i<n; i++){
            h -= pow*nums[i-len];
            h = h*base + nums[i];

            if(freq[h] == 1)return true;
        }

        return false;
    }
    
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 1;
        int r = n;
        int ans = n;

        while(l <= r){
            int m = l + (r-l)/2;

            if(check(m,nums)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return ans;
    }
};
