//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int f(int k, vector<int>&nums,vector<vector<int>>&queries){
        int n=nums.size();
        vector<int>mpp(n+1,0);
        for(int i=0; i<k; i++){
            mpp[queries[i][0]]+=queries[i][2];
            mpp[queries[i][1]+1]-=queries[i][2];
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=mpp[i];
            if(cnt<nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int l=0,h=queries.size();
        int res=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(f(mid,nums,queries)){
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};
