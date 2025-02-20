//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
       string res;
       for(int i=0; i<n; i++){
           char ch=nums[i][i];
           if(ch=='0'){
               res+='1';
           }
           else{
               res+='0';
           }
       }
       return res;
    }
};
