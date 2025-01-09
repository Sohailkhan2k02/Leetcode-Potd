//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(auto i:words){
            if(i.find(pref)==0) cnt++;
        }
        return cnt;
    }
};
