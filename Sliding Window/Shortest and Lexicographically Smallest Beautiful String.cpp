class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        int cnt=0;
        int mini=INT_MAX;
        int start=-1;
        string ans="";
        while(j<n){
            if(s[j]=='1'){
                cnt++;
            }
            while(cnt>=k){
                mini=min(mini,j-i+1);
                string res=s.substr(i,j-i+1);
                if(ans.size()==0 || res.size()<ans.size()){
                    ans=res;
                }
                else if(ans.size()==res.size()){
                    ans=min(ans,res);
                }
                if(s[i]=='1'){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
