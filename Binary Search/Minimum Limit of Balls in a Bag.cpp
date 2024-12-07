//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:
    bool f(int b, vector<int>&nums, int maxOperations){
        int cnt=0,n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>b){
                cnt+=(nums[i]-1)/b;
            }
            if(cnt>maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1,h=*max_element(nums.begin(),nums.end());
        int res=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(f(m,nums,maxOperations)){
                res=m;
                h=m-1;
            }
            else l=m+1;
        }
        return res;
    }
};
