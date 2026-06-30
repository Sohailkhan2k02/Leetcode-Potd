class Solution {
public:
    // APPROACH -1 USING SLIDNG WINDOW WITH MAP TC O(N) SC O(N)
    // int numberOfSubstrings(string s) {
    //     int n=s.size();
    //     int i=0,j=0;
    //     unordered_map<char,int>mpp;
    //     int cnt=0;
    //     while(j<n){
    //         mpp[s[j]]++;
    //         while(mpp.size()==3){
    //             cnt+=n-j;
    //             mpp[s[i]]--;
    //             if(mpp[s[i]]==0){
    //                 mpp.erase(s[i]);
    //             }
    //             i++;
    //         }
    //         j++;
    //     }
    //     return cnt;
    // }

    // APPROACH -2 USING BETTER SPACE TC O(N) SC O(1)
    // MORE OPTIMISE USING VECTOR TO STORE ONLY 3 CHARACTERS SINCE 
    // IN THE CONSTRAINTS s only consists of a, b or c characters.
    int numberOfSubstrings(string s){
        int n=s.size();
        int i=0,j=0;
        int cnt=0;
        vector<int>mpp(3,0);
        while(j<n){
            mpp[s[j]-'a']++;
            while(mpp[0]>0 && mpp[1]>0 && mpp[2]>0){
                cnt+=n-j;
                mpp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return cnt;
    }

};
