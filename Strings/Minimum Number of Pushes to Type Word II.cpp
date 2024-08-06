//T.C : O(n)
//S.C: O(1)
class Solution {
public:
    int minimumPushes(string word){
        vector<int>mpp(26,0);
        for(char &ch: word){
            mpp[ch-'a']++;
        }
        sort(mpp.rbegin(), mpp.rend());
        int result=0;
        for(int i=0; i<26; i++){
            int freq=mpp[i];
            int count=(i/8)+1;
            result+=freq*count;
        }
        return result;
    }
};
