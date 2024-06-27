//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>>mpp;
        for(auto vec:edges){
            int u=vec[0],v=vec[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        for(auto vec:edges){
            int u=vec[0],v=vec[1];
            if(mpp[u].size()==n){
                return u;
            }
            if(mpp[v].size()==n){
                return v;
            }
        }
        return -1;
    }
};

//Approach-2 (Constant time)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      if(edges[0][0]==edges[1][1] || edges[0][0]==edges[1][0]){
            return edges[0][0];
        }
        return edges[0][1];
    }
};

