//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    string f(int i){
        if(i==1) return "0";
        if(i==2) return "011";
    
        string res=f(i-1);
        string t=res;
        for(int j=0; j<t.size(); j++){
            t[j]=(1^(t[j]-'0'))+'0';
        }
        reverse(t.begin(),t.end());
        res+="1";
        res+=t;
        return res;
    }
    char findKthBit(int n, int k) {
        string s=f(n);
        return s[k-1];
    }
};
