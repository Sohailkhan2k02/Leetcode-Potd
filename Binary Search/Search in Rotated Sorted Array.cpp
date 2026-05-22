class Solution {
public:
    int pivot(vector<int>&nums, int n){
        int l=0,h=n-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(nums[m]>nums[h]){
                l=m+1;
            }
            else h=m;
        }
        return h;
    }
    int f(int l, int h, vector<int>&nums, int k){
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==k){
                return m;
                break;
            }
            else if(nums[m]<k){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        int pivotIdx=pivot(nums,n);
        int idx=f(0,pivotIdx-1,nums,target);
        if(idx!=-1) return idx;
        return f(pivotIdx,n-1,nums,target);
    }
};
