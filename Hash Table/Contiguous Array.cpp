//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mpp;
        int len=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                sum+=1;
            }
            else{
                sum-=1;
            }
            if(sum==0){
                len=max(len,i+1);
            }
            else if(mpp.find(sum)!=mpp.end()){
                len=max(len,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return len;
    }
};
