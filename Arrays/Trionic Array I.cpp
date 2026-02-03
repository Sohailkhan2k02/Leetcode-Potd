class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        const int n=nums.size();
        if (nums[0]>=nums[1] || n<4) return 0;
        int q=0, t=0;
        for(int i=2; i<n; i++){
            while(i<n && nums[i-1]<nums[i]){
                i++;
            }
            if (i<n && nums[i-1]==nums[i]) return 0;
            while(i<n && nums[i-1]>nums[i]){
                i++;
            }
            if (i<n && nums[i-1]==nums[i]) return 0;
            q=i;
            while(i<n && nums[i-1]<nums[i]){
                i++;
            }
            t=i;
            if (t<n) return 0;
        }
    //    cout<<q<<endl;
        return q>1 && q<n;
    }
};
