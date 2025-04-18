//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string res=countAndSay(n-1);
        string ans="";
        for(int i=0; i<res.size(); i++){
            char ch=res[i];
            int cnt=1;

            while(i<res.size()-1 && res[i]==res[i+1]){
                cnt++,i++;
            }
            // WE CAN CONVERT CHAR CH TO STRING USING STRING(1,CH);
            ans+=to_string(cnt)+string(1,ch);
        }
        return ans;
    }
};
