class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
      unordered_map<int,vector<int>>adj;
      int n=colors.size();
      vector<int>indegree(n,0);
      for(auto &e:edges)
      {
        int u=e[0];
        int v=e[1];
        adj[u].push_back(v);
        indegree[v]++;
      }
      vector<vector<int>>t(n,vector<int>(26,0));  
      queue<int>q;
      for(int i=0;i<n;i++)
      {
        if(indegree[i]==0) 
        {
            q.push(i);
            t[i][colors[i]-'a']=1;
        }
      }
      int ans=0;
      int countNodes=0; //to detect the cycle in a graph
      while(!q.empty())
      {
        int u=q.front();
        q.pop();
        countNodes++;
        ans=max(ans,t[u][colors[u]-'a']);
        for(int &v:adj[u])
        {
           for(int i=0;i<26;i++)
           {
             t[v][i]=max(t[v][i],t[u][i]+(colors[v]-'a'==i));
          
           }
        indegree[v]--;
        if(indegree[v]==0) q.push(v);
        }   
      }
      if(countNodes<n) return -1; //cycle
      return ans;

    }
};
