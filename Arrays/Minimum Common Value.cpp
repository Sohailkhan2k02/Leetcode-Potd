class Solution {
public:

    // APPROACH - 1 
    // int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //     int n=nums2.size();
    //     unordered_map<int,int>mpp;
    //     for(auto i:nums1){
    //         mpp[i]++;
    //     }
    //     vector<int>ans;
    //     bool common=false;
    //     for(int i=0; i<n; i++){
    //         if(mpp.find(nums2[i])!=mpp.end()){
    //             ans.push_back(nums2[i]);
    //             common=true;
    //         }
    //     }
    //     if(common==false){
    //         return -1;
    //     }
    //     int res=0;
    //     for(int i=0; i<ans.size(); i++){
    //         cout<<ans[i]<<endl;
    //         res=ans[0];
    //     }
    //     return res;
    // }


    // APPROACH - 2 
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]==nums2[j]){
                return nums1[i];
                break;
            }
        }
        return -1;
    }
};
