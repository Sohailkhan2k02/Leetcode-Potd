//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        using ll=long long;
        int n=nums.size();
        vector<pair<int,int>>vc;
        for(int i=0; i<n; i++){
            vc.push_back({i,nums[i]});
        }
        sort(vc.begin(),vc.end(),[&](pair<int,int>&a, pair<int,int>&b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        vector<int>vis(n,0);
        ll sum=0;
        for(int i=0; i<n; i++){
            if(!vis[vc[i].first]){
                sum+=vc[i].second;
                vis[vc[i].first]=1;
                if(vc[i].first-1>=0){
                    vis[vc[i].first-1]=1;
                }
                if(vc[i].first+1<n){
                    vis[vc[i].first+1]=1;
                }
            }
        }
        return sum;
    }
};
