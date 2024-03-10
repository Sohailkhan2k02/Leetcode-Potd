//T.C : O(nums1.size() + nums2.size() + st.size())
//S.C : O(nums1.size() + min(nums1.size(), nums2.size()))

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        int n=nums2.size();
        for(auto i:nums1){
            mpp[i]++;
        }
        set<int>st;
        for(int i=0; i<n; i++){
            if(mpp.find(nums2[i])!=mpp.end()){
                st.insert(nums2[i]);
            }
        }
        vector<int>res(st.begin(),st.end());
        return res;
    }
};
