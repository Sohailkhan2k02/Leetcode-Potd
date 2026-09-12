class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> a(n,vector<int>(4,0));
        for(int i=0;i<n;i++){
            a[i][0]=intervals[i][0];
            a[i][1]=intervals[i][1];
            a[i][2]=intervals[i][2];
            a[i][3]=i;
        }
        sort(a.begin(),a.end());
        vector<int> ls(n,0);
        for(int i=0;i<n;i++) ls[i]=a[i][0];
        vector<vector<long long>> s(n+1,vector<long long>(5,0));
        vector<vector<vector<int>>> p(n+1,vector<vector<int>>(5));
        for(int i=n-1;i>=0;i--){
            int nx=upper_bound(ls.begin(),ls.end(),a[i][1])-ls.begin();
            for(int k=1;k<=4;k++){
                s[i][k]=s[i+1][k];
                p[i][k]=p[i+1][k];
                long long t=(long long)a[i][2]+s[nx][k-1];
                vector<int> q=p[nx][k-1];
                q.push_back(a[i][3]);
                sort(q.begin(),q.end());
                if(t>s[i][k] || (t==s[i][k] && q<p[i][k])){
                    s[i][k]=t;
                    p[i][k]=q;
                }
            }
        }
        return p[0][4];
    }
};
