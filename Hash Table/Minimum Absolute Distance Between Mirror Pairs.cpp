class Solution {
public:
int reverseDigits(int num){
  int rev_num = 0;
  while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
    int minMirrorPairDistance(vector<int>& nums) {
       unordered_map<int,int>mp;
       int ans=1000000;
       for(int i=0;i<nums.size();i++){
           if(mp.find(nums[i])!=mp.end()){
              ans=min(ans,abs(mp[nums[i]]-i));
           }
           mp[reverseDigits(nums[i])]=i;
       }
       return (ans==1000000?-1:ans); 
    }
};
