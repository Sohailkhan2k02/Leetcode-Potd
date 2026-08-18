class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> d;
        for(int x:nums) d[x]++;

        int a=nums[0],b=nums.back();
        int da=d[a],db=d[b];

        if(k==nums.size())
            return *max_element(nums.begin(),nums.end());

        if(k==1){
            int mx=-1;
            for(auto i:d){
                if(i.second==1)
                    mx=max(mx,i.first);
            }
            return mx;
        }

        if(a==b)
            return -1;
        else if(da>1 && db>1)
            return -1;
        else if(da>1 && db==1)
            return b;
        else if(db>1 && da==1)
            return a;
        else if(da==1 && db==1)
            return max(a,b);

        return -1;
    }
};
