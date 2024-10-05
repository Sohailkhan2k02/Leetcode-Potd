//T.C : O(n+m)
//S.C : O(n) use vector so space will be O(26) constant
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        unordered_map<int,int>mpp;
        for(auto i:s1){
            mpp[i]++;
        }

        int j=0,i=0,m=s2.size();
        int len=mpp.size();
        while(j<m){
            if(mpp.find(s2[j])!=mpp.end()){
                mpp[s2[j]]--;
                if(mpp[s2[j]]==0) len--;
            }
            if(j-i+1>n){
                if(mpp.find(s2[i])!=mpp.end()){
                    if(mpp[s2[i]]==0) len++;
                    mpp[s2[i]]++;
                }
                i++;
            }

            if(len==0){
                return true;
            }
            j++;
        }
        return false;
    }
};
