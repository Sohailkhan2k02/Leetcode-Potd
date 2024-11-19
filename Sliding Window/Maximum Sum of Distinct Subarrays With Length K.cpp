//APPROACH -1
//T.C : O(n)
//S.C : O(100001)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        using ll=long long;
        ll maxi=0,sum=0;
        int i=0,j=0;
        unordered_map<ll,ll>mpp;
        while(j<n){
            mpp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1==k){
                if(mpp.size()==k){
                    maxi=max(maxi,sum);
                }
                mpp[nums[i]]--;
                sum-=nums[i];
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return maxi;
    }
};

// APPROACH -2
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        using ll=long long;
        ll maxi=0,sum=0;
        int i=0,j=0;
        // unordered_map<ll,ll>mpp;
        bitset<100001>bt=0;
        while(j<n){
            sum+=nums[j];
            while(i<j && (j-i+1>k || bt[nums[j]])){
                bt[nums[i]]=0;
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k){
                maxi=max(maxi,sum);
            }
            bt[nums[j]]=1;
            j++;
        }
        return maxi;
    }
};
