//T.C : O(max(s1.size(),s2.size());
//S.C : O(n+m)
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        stringstream ss1(s1),ss2(s2);
        vector<string>v1,v2;
        string token="";
        while(ss1>>token){
            v1.push_back(token);
        }
        token="";
        while(ss2>>token){
            v2.push_back(token);
        }

        int i=0,j=v1.size()-1;
        int k=0,l=v2.size()-1;
        while(i<=j && k<=l && v1[i]==v2[k]){
            i++,k++;
        }
        while(i<=j && k<=l && v1[j]==v2[l]){
            j--,l--;
        }
        return i>j || k>l;
    }
};
