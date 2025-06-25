class Solution {
public:

    long long countPositive(vector<int>& nums2,int a, long long tar){

        int l = 0, r = nums2.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if((1LL*a*nums2[mid]) <= tar){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return l;
    }

    long long countNegative(vector<int>& nums2,int a, long long tar){

        int l = 0, r = nums2.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if((1LL*a*nums2[mid]) <= tar){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return nums2.size() - l;
    }

    long long cntProduct(vector<int>& nums1, vector<int>& nums2, long long mid){

        long long cnt = 0;
        for(auto a:nums1){
            if(a>=0){
                cnt += countPositive(nums2,a,mid); // cnt product of a*nums2[j] less than equal to mid
            }
            else{
                cnt += countNegative(nums2,a,mid);
            }
        }

        return cnt;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        long long l = -1e10, r = 1e10;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(cntProduct(nums1,nums2,mid)<k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return l;
    }
};
