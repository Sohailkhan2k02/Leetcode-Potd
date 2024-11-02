//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        char ch1=' ',ch2=' ';
        string s="";
        string temp="";
        vector<string>res;
        stringstream ss(sentence);
        while(getline(ss,temp,' ')){
            ch1=temp[0];
            ch2=temp[temp.size()-1];
            s+=ch1;
            s+=ch2;
            res.push_back(s);
            s="";
        }
        char ch=' ';
        for(int i=0; i<res.size()-1; i++){
            ch=res[i][1];
            if(ch!=res[i+1][0]){
                return false;
            }
        }
        if(res[res.size()-1][1]!=res[0][0]) return false;
        return true;
    }
};
