//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0; i<n; i++){
            // int x=nums[i];
            // int c=0;
            // while(x>0){
            //     c++;
            //     x=x/10;
            // }
            // if(c%2==0) cnt++;
            if(to_string(nums[i]).size()%2==0) cnt++;
        }
        return cnt;
    }
};
