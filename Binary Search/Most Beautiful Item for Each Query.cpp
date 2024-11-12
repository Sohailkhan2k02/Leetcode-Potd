//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        vector<int>res(n,0);
        sort(items.begin(),items.end());
        // for(auto i:items) cout<<i[0]<<" "<<i[1]<<" ";
        for(int i=1; i<items.size(); i++){
            items[i][1]=max(items[i][1],items[i-1][1]);
        }
        for(int i=0; i<n; i++){
            int l=0,h=items.size()-1;
            int ans=0;
            while(l<=h){
                int m=l+(h-l)/2;
                if(items[m][0]<=queries[i]){
                    ans=items[m][1];
                    l=m+1;
                }
                else{
                    h=m-1;
                }
                res[i]=ans;
            }
        }
        return res;
    }
};
