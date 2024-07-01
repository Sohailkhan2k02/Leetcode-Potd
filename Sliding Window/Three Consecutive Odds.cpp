//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0;
        while(j<n){
            if(j-i+1==3){
                if(arr[i]&1 && arr[i+1]&1 && arr[i+2]&1){
                    return true;
                }
                i++;
            }
            j++;
        }
        return false;
    }
};
