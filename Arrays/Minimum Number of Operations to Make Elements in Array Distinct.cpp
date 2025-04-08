//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isUnique(map<int,int>mpp){
        for(auto [u,f]:mpp){
            if(f>1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        int j=0,k=j+1,l=j+2;
        while(1){
            if(isUnique(mpp)) break;
            else{
                if(j<n){mpp[nums[j]]--;}
                if(k<n){mpp[nums[k]]--;}
                if(l<n){mpp[nums[l]]--;}
                cnt++;
                j+=3,k+=3,l+=3;
            }
        }
        return cnt;
    }
};
