class Solution {
public:
    int helper(int i,int j,vector<vector<int>> &events,vector<int> &next,int n,vector<vector<int>> &dp,int k){
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(j<k)
        ans=max(ans,events[i][2]+helper(next[i],j+1,events,next,n,dp,k));
        ans=max(ans,helper(i+1,j,events,next,n,dp,k));
        return dp[i][j]=ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) {
          if (a[0] == b[0])
            return a[1] < b[1];
          return a[0] < b[0];
        });
        vector<int> next(n,-1);
        for(int i=0;i<n;i++){
            int temp=events[i][1];
            int s=0; int e=n-1; int ans=n;
            while(s<=e){
                int mid=(s+e)/2;
                if(events[mid][0]>temp){
                    ans=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            next[i]=ans;
        }

        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        return helper(0,0,events,next,n,dp,k);
    }
};
