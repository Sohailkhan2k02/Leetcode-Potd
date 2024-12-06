//T.C : O(n)
//S.C : O(banned.size())
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(banned.begin(),banned.end());
        int sum=0;
        int j=1,cnt=0,maxi=0;
        for(int i=1; i<=n; i++){
            if(st.find(i)!=st.end()) continue;
            sum+=i;
            cnt++;
            while(sum>maxSum){
                sum-=j;
                cnt--;
                j++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
