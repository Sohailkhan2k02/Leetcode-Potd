//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        while(i+1<n && arr[i]<=arr[i+1]) i++;
        if(i==n-1) return 0;
        while(j>0 && arr[j-1]<=arr[j]) j--;
        int mini=min(j,n-i-1);
        int l=0,r=j;
        while(l<=i && r<n){
            if(arr[l]<=arr[r]){
                mini=min(mini,r-l-1);
                l++;
            }
            else r++;
        }
        return mini;
    }
};
