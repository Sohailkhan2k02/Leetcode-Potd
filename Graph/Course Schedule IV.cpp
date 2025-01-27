//T.C : O(n)
//S.C : O(n)
class Solution {
public:

    bool canvisit(int node, int target, vector<int> adj[], int n){ // to find if we can visit the other node!

        queue<int> q;
        vector<int> vis(n,0);
        vis[node]=1;
        q.push({node});

        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num==target) return true;

            for(auto it: adj[num]){
                if(vis[it]==0){
                    if(it==target) return true;
                    q.push(it); vis[it]=1;
                }
            }
        }
    return false; // if we cannot reach the other node
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        //0 based indexing
        //n =  no of courses from 0 to n-1

        vector<bool>ans(queries.size(), false); // ans vector initialised with false *NOTE*
        if(prereq.size()==0) return ans; // see testcase

        // first lets find toposort using kahn's algo (bfs)

        vector<int> adj[n];
        vector<int> indegree(n,0); // indegree[i] = incoming edges to node i

        for(auto it: prereq){
            adj[it[0]].push_back(it[1]); //directed graph
            indegree[it[1]]++;
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        //topo vector is ready!

        for(int i=0; i<queries.size(); i++){
            int n1 = queries[i][0];
            int n2 = queries[i][1];

            for(int j=0; j<topo.size(); j++){ //loking in the topo vector
                if( topo[j]==n1 && canvisit(n1,n2,adj,n) ){ //=> if we see n1 first and canvisit n2 from n1
                    ans[i]=true;
                    break;
                }
                if(topo[j]==n2){
                    break;
                }
            }
        }

        return ans;
        
    }
};
