//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int l = i+1,r=nums.size()-1;
            int x=0,xx=0;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(nums[mid]+nums[i]<lower){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            x=l;
            l=i+1,r=nums.size()-1;
            while(l<r){
                int mid = l + (r-l)/2;
                if(nums[i]+nums[mid]>upper){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            xx=l;
            int n = nums.size();
            if(xx>=0 && x>=0 && xx<n && x<n){
                if(nums[i]+nums[x]>=lower && nums[xx]+nums[i]<=upper){
                    ans += (xx-x+1);
                }else if(nums[i]+nums[x]>=lower && nums[xx-1]+nums[i]<=upper){
                    ans += (xx-x);
                }
            }
        }
        return ans;
    }
};
