class Solution {
public:
     string s;
     int n;
     int idx = 0;
     set<string> getUnit(){
             set<string>  res;
             if(s[idx] == '{'){
                idx++;
               res = performUnion();
             }
             else{
                res = {string(1,s[idx])};
             }
             idx++;
             return res;
     }
     set<string> performConcat(){
        set<string>r = {""};
        while(idx < n && (s[idx] == '{' ||  isalpha(s[idx]))){
            set<string>t = getUnit();
            set<string> concatRes;
            for(const string& left : r){
                for(const string& right :t){
                    concatRes.insert(left+right);
                }
            }
            r = concatRes;
        }
        return r;
     }
     set<string> performUnion(){
          set<string>res;
          while(true){
            set<string> temp = performConcat();
            res.insert(begin(temp),end(temp));
            if(idx < n && s[idx]==',') idx++;
            else break;
          }
          return res;
     }
    vector<string> braceExpansionII(string exp) {
        n = exp.length();
        s = exp;
        idx = 0;

       set<string>str = performUnion();
       vector<string> res(begin(str),end(str));
       return res;

    }
};
