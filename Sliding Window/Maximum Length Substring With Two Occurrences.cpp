class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<int,int>mpp;
        int i=0,j=0;
        int maxi=INT_MIN;
        while(j<n){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
