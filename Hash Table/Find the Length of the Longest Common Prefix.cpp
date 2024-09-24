//T.C : O(max(n*arr1[i].size(),m*arr2[i].size()))
//S.C : O(n*arr1[i].size() + arr2[i].size())
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(),m=arr2.size();
        int maxi=0;
        unordered_map<string,int>mpp;
        for(int i=0; i<n; i++){
            string s=to_string(arr1[i]);
            string curr="";
            for(int j=0; j<s.size(); j++){
                curr+=s[j];
                mpp[curr]++;
            }
        }
        for(int i=0; i<m; i++){
            string s=to_string(arr2[i]);
            string curr="";
            for(int j=0; j<s.size(); j++){
                curr+=s[j];
                if(mpp.find(curr)!=mpp.end()){
                    maxi=max(maxi,(int)curr.size());
                }
                else break;
            }
        }
        return maxi;
    }
};
