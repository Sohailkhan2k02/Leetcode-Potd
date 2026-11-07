class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        int n = servers.size(), m = tasks.size();
        using ll = long long;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> free, work;
        vector<int> ans(m);
        for(int i = 0; i<n; i++)free.push({servers[i], i});
        for(ll i = 0, time = 0; i<m;){
            if(free.empty())time = work.top().first;

            while(work.size() && work.top().first <= time){
                auto [t, idx] = work.top();
                free.push({servers[idx], idx});
                work.pop();
            }

            while(i < m && i <= time && free.size()){
                auto [t, idx] = free.top();
                free.pop();
                ans[i] = idx;
                work.push({time + tasks[i++], idx});
            }
            time++;
        }
        return ans;
    }
};
