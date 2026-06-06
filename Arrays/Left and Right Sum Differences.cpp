class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n,0);
        vector<int>b(n,0);
        a[0]=0;
        for(int i=1;i<nums.size();i++)a[i]=a[i-1]+nums[i-1];
        b[n-1]=0;
        for(int j=n-2;j>=0;j--)b[j]=b[j+1]+nums[j+1];
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(abs(a[i]-b[i]));
        }
        return ans;
    }
};
