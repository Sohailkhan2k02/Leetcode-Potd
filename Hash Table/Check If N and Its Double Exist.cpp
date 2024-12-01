//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mpp;
        for(auto i:arr) mpp[i]++;
        for(int i=0; i<n; i++){
            if(mpp.find(arr[i]*2)!=mpp.end()){
                if(arr[i]!=0 || mpp[arr[i]]>1){
                    return true;
                }
            }
        }
        return false;
    }
};
