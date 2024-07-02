//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp;
        for(auto i:nums1) mpp[i]++;
        vector<int>res;
        for(auto i:nums2){
            if(mpp.find(i)!=mpp.end() && mpp[i]>0){
                res.push_back(i);
                mpp[i]--;
            }
        }
        return res;
    }
};
