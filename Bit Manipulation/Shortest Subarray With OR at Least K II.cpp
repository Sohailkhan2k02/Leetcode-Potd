//T.C: O(30*n)
//S.C : O(30)
class Solution {
public:
    void f1(int &val, int &_or, vector<int>&mpp){
        _or=_or|val;
        for(int i=0; i<30; i++){
            if(val&(1<<i)) mpp[i]+=1;
        }
    }
    void f2(int &val, int &_or, vector<int>&mpp){
        for(int i=0; i<30; i++){
            if(val&(1<<i)){
                mpp[i]-=1;
            }
            if(mpp[i]==0) _or=_or&(~(1<<i));
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,_or=0;
        // long long num=1000000000;
        // cout<<floor(log2(num))+1;  // ONLY 30 BITS REQUIRED
        vector<int>mpp(30,0);
        int len=INT_MAX;
        while(j<n){
            f1(nums[j],_or,mpp);
            while(i<=j && _or>=k){
                if(len>j-i+1){
                    len=j-i+1;
                }
                f2(nums[i],_or,mpp);
                i++;
            }
            j++;
        }
        if(len==INT_MAX){
            return -1;
        }
        return len;
    }
};
