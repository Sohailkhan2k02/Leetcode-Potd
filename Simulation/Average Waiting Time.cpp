//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n=c.size();
        long long cumsum=0;
        long long sum=0;
        for(int i=0; i<n; i++){
            int u=c[i][0],v=c[i][1];
            if(u>cumsum){
                cumsum=u+v;
                v=u+v;
                int diff=v-u;
                sum+=diff;
            }
            else{
                // cout<<u<<" ";
                cumsum+=v;
                // cout<<cumsum<<" ";
                long long diff=cumsum-u;
                sum+=diff;
            }
            // cout<<"\n";
            cout<<cumsum<<" ";
        }
        // cout<<"\n";
        // cout<<sum<<" ";
        return (double)sum/(double)n;
    }
};
