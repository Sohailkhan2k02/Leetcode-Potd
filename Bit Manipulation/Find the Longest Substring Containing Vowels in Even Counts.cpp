//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mask;
        // a as 00001,e as 00010,i as 00100, o as 01000, u as 10000
        mask['a']=1,mask['e']=2,mask['i']=4,mask['o']=8,mask['u']=16;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int len=0,xr=0;
        for(int i=0; i<n; i++){
            xr^=mask[s[i]];
            if(mpp.find(xr)!=mpp.end()){
                len=max(len,i-mpp[xr]);
            }
            else{
                mpp[xr]=i;
            }
        }
        return len;
    }
};
