class Solution {
public:
typedef long long ll;
    long long maxSubarrays(int n, vector<vector<int>>& conflict) {
        vector<vector<int>>right(n+1);
        for(int i=0;i<conflict.size();i++){
            right[max(conflict[i][0],conflict[i][1])].push_back(min(conflict[i][0],conflict[i][1]));
        }
        ll ans=0;
        vector<int>left={0,0};
        vector<ll>bonus(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j:right[i]){
                if(j>left[0]){
                    left={j,left[0]};
                }else if(j>left[1]){
                    left={left[0],j};
                }
            }
            ans+=i-left[0];
            bonus[left[0]]+=left[0]-left[1];
        }
        ll maxi=0;
        for(ll b:bonus){
            maxi=max(maxi,b);
        }
        return maxi+ans;
    }
};
