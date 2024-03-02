//Approach-1
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i]*nums[i];
        }
        
        sort(begin(nums), end(nums)); //O(nlogn)
        return nums;
    }
};


//Approach-2 (Follow Up, without sorting nlogn)
//T.C : O(n)
//S.C : O(1) - (Not considering the space takent to store the result)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0,j=n-1,k=n-1;
        while(i<=j){
            int cmp1,cmp2;
            cmp1=nums[i]*nums[i];
            cmp2=nums[j]*nums[j];

            if(cmp1>cmp2){
                ans[k--]=cmp1;
                i++;
            }
            else{
                ans[k--]=cmp2;
                j--;
            }
        }
        return ans;
    }
};
