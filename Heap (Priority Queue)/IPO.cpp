//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n=p.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({c[i],p[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int i=0;
        while(k--){
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top();pq.pop();
        }
        return w;
    }
};
