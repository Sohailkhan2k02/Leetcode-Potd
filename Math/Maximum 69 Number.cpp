class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        string maxi="";
        for(int i=0; i<s.size(); i++){
            string t1=s,t2=s;
            t1[i]='6',t2[i]='9';
            maxi=max({maxi,s,t1,t2});
        }
        // cout<<maxi<<" ";
        return stoi((maxi));
    }
};
