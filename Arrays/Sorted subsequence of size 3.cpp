//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size(), a=INT_MAX, b=INT_MAX;
        for(int i=1; i<n; i++){
            if(arr[i] > b) return {a, b, arr[i]};
            if(arr[i] > a && arr[i] < b) b=arr[i];
            else if(arr[i] > arr[i-1]){
                a=arr[i-1];
                b=arr[i];
            }
        }
        return {};
    }

};
