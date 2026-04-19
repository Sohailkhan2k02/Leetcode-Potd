class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxie=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            auto it=upper_bound(nums2.begin()+i,nums2.end(),nums1[i],greater<int>());
            int j=it-nums2.begin()-1;
            if(j>=i){maxie=max(maxie,j-i);}
        }
        return (maxie==INT_MIN)?0:maxie;
    }
};
