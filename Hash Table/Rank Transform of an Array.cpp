//T.C : O(n*logn)
//S.C : O(unique element)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>res=arr;
        sort(res.begin(),res.end());
        unordered_map<int,int>mpp;
        int cnt=1;
        for(int i=0; i<n; i++){
            if(mpp.find(res[i])==mpp.end()){
                mpp[res[i]]=cnt;
                cnt++;
            }
        }
        for(int i=0; i<n; i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;
    }
};
