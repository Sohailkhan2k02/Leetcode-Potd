//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        int n=a2.size();
        map<int,int>mpp;
        for(int i=0; i<n; i++){
            mpp[a2[i]]=i;
        }
        auto cmp=[&mpp](int a, int b){
            bool s1=mpp.find(a)!=mpp.end();
            bool s2=mpp.find(b)!=mpp.end();

            if(s1&&s2){
                return mpp[a]<mpp[b];
            }
            else if(s1){
                return true;
            }
            else if(s2){
                return false;
            }
            else{
                return a<b;
            }
        };

        sort(a1.begin(),a1.end(),cmp);
        return a1;
    }
};
