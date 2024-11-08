//T.C : O(32*n)
//S.C : O(n*32)
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int>ans;
        vector<int>bit(32,0);
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]&(1<<i))
                bit[i]++;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            int x=0;
            for(int j=0;j<maximumBit;j++)
            {
                if(bit[j]%2==0)
                x+=(1<<j);
            }
            ans.push_back(x);
            for(int j=0;j<32;j++)
            {
                if(nums[i]&(1<<j))
                bit[j]--;
            }
        }
        return ans;
    }
};
