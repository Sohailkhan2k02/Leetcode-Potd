//T.C : O(NLOGN)
//S.C : O(N)
class Solution {
public:
    int findMinDifference(vector<string>& t) {
        int n=t.size();
        vector<int>tt;
        int mini=INT_MAX;
        int temp;
        for(int i=0;i<n; i++){
            temp=stoi(t[i].substr(0,2))*60;
            temp+=stoi(t[i].substr(3,2));
            tt.push_back(temp);
        }
        sort(tt.begin(),tt.end());
        for(int i=1; i<n; i++){
            mini=min(mini,tt[i]-tt[i-1]);
        }        
        return min(mini,(1440-tt[n-1])+tt[0]);
    }
};
