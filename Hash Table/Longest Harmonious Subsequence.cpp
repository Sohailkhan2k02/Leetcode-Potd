class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=-1;
        
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            mp[x]++;
            if(mp.find(x-1)!=mp.end()){
                ans=max(ans,mp[x]+mp[x-1]);
            }
            if(mp.find(x+1)!=mp.end()){
                ans=max(ans,mp[x+1]+mp[x]);
            }
          
        }
        return ans==-1?0:ans;
    }
};
