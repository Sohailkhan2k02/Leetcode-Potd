//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        map<int, int> cnt, color;
        int n = q.size();
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            int x = q[i][0];
            int y = q[i][1];
            if(color.find(x) != color.end()){
                cnt[color[x]]--;
                if(cnt[color[x]] == 0)  cnt.erase(color[x]);
            }
            
            color[x] = y;
            cnt[y]++;
            ans[i] = cnt.size();
        }
        
        return ans;
    }
};
