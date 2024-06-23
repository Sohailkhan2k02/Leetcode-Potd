//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0;
        deque<int>mini,maxi;
        int i=0,j=0;
        while(j<n){
            while(!mini.empty() && mini.back()>nums[j]) mini.pop_back();
            while(!maxi.empty() && maxi.back()<nums[j]) maxi.pop_back();

            mini.push_back(nums[j]);
            maxi.push_back(nums[j]);

            int a=maxi.front(),b=mini.front();
            if(abs(a-b)>k){
                if(a==nums[i]){
                    maxi.pop_front();
                }
                if(b==nums[i]){
                    mini.pop_front();
                }
                i++;
            }

            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};
