class Solution {
public:
    int maximumLength(vector<int>& nums) {
        long long n = nums.size(), ans = 1;
        unordered_map<long long, long long> mp;
        for(auto i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(auto &[k, v]: mp){
            if(k == 1){
                if(v%2 == 0){
                    ans = max(ans, v - 1);
                }
                else ans = max(ans, v);
                continue;
            }
            if(v >= 2){
                long long nk = k*k, cnt = 2;
                while(mp.count(nk)){
                    if(mp[nk] == 1){
                        cnt += 1;
                        break;
                    }
                    cnt += 2;
                    nk = nk*nk;
                }
                if(cnt%2 == 0) cnt--;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
