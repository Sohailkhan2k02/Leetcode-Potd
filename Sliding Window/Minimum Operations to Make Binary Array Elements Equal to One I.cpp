//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int cnt=0;
        while(j<n){
            if(j-i+1==3){
                if(nums[i]==0){
                    nums[i]^=1;
                    nums[i+1]^=1;
                    nums[i+2]^=1;
                    cnt++;
                }
                i++;
            }
            j++;
        }
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cnt=-1;
            }
        }
        return cnt;
    }
};
