//T.C : O(n*logk)
//S.C : O(k)
class Solution {
public:
    using ll=long long;
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;
        for(auto i:nums){
            pq.push(i);
        }
        ll sum=0;
        while(!pq.empty() && k-->0){
            auto val=pq.top();
            pq.pop();
            sum+=val;
            pq.push((val+2)/3);
        }
        return sum;
    }
};
