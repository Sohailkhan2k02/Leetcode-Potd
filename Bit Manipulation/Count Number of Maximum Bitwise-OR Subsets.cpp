class Solution {
public:
    int cnt=0;
    void f(int i, vector<int>&nums, int mxx,int curr){
        int n=nums.size();
        if(i==n){
            if(curr==mxx){
                cnt++;
            }
            return;
        }

        f(i+1,nums,mxx,curr|nums[i]);
        f(i+1,nums,mxx,curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int mxx=0,a=0;
        if(n==1) return 1;
        for(int i=0; i<n; i++){
            a=a|nums[i];
            // cout<<a;
            mxx=max(mxx,a);
        }
        f(0,nums,mxx,0);
        return cnt;
    }
};
