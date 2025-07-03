//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string temp="";
            for(int i=0; i<s.size(); i++){
                char t='a'+(s[i]-'a'+1)%26;
                temp+=t;
            }
            s+=temp;
        }
        cout<<s<<" ";
        return s[k-1];
    }
};
