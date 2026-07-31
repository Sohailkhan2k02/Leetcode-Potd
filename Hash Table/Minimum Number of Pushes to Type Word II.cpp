class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mpp(26,0);
        for(auto i:word){
            mpp[i-'a']++;
        }
        sort(mpp.rbegin(),mpp.rend());
        int cnt=0;
        for(int i=0; i<26; i++){
            cnt+=mpp[i]*((i/8)+1);
        }
        return cnt;
    }
};
