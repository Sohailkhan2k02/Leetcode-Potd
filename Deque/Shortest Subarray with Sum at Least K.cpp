//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        using ll=long long;
        int n=nums.size();
        vector<ll>pre(n+1,0);
        for(int i=0; i<n; i++){
            pre[i+1]=pre[i]+nums[i];
        }
        deque<ll>dq;
        ll len=INT_MAX;
        for(int i=0; i<=n; i++){
            while(!dq.empty() && pre[i]-pre[dq.front()]>=k){
                len=min(len,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && pre[i]<=pre[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(len==INT_MAX) return -1;
        return len;
    }
};
