//T.C : O(n*logn)+O(n)+O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mpp;
        for(auto i:nums) mpp[i]++;
        auto lambda=[&](int a, int b){
            if(mpp[a]==mpp[b]){
                return a>b;
            }
            return mpp[a]<mpp[b];
        };
        sort(nums.begin(),nums.end(),lambda);
        vector<int>res(nums.begin(),nums.end());
        return res;
    }
};
