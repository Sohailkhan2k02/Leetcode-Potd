class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>>mpp[n];
        vector<int>time(n,INT_MAX);
        for(auto vec:meetings){
            int u=vec[0];
            int v=vec[1];
            int time=vec[2];

            mpp[u].push_back({v,time});
            mpp[v].push_back({u,time});
        }

        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({firstPerson,0});
        time[0]=0;
        time[firstPerson]=0;
        while(!q.empty()){
            int u=q.front().first;
            int t=q.front().second;
            q.pop();

            for(auto vec:mpp[u]){
                int v=vec.first;
                int actualtime=vec.second;

                if(actualtime>=t && time[v]>actualtime){
                    time[v]=actualtime;
                    q.push({v,actualtime});
                }
            }
        }

        vector<int>res;
        for(int i=0; i<n; i++){
            if(time[i]!=INT_MAX){
                res.push_back(i);
            }
        }
        return res;
    }
};
