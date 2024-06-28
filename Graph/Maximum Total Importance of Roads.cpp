//T.C : O(E + nlogn)
//S.C : O(n)
#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<ll,ll>mpp;
        for(auto vec:roads){
            int u=vec[0],v=vec[1];
            mpp[u]++,mpp[v]++;
        }
        vector<ll>res(n,0);
        for(int i=0; i<n; i++){
            res[i]=mpp[i];
        }
        sort(res.begin(),res.end());
        ll sum=0;
        for(int i=0; i<n; i++){
            sum+=res[i]*(i+1);
        }
        return sum;
    }
};
