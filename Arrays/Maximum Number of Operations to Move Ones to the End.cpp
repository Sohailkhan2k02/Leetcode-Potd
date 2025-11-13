class Solution {
public:
    int maxOperations(string s) {
        int cnt=0,res=0,f=0;
        for(auto i:s){
            if(i=='1') cnt++,f=1;
            else if(f) res+=cnt,f=0;
        }
        return res;
    }
};
