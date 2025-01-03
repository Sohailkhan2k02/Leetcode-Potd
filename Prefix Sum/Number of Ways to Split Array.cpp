//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]>=(pre[n-1]-pre[i])){
                cnt++;
            }
        }
        return cnt;
    }
};
