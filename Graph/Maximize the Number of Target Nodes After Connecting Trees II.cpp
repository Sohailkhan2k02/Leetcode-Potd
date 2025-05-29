class Solution {
public:
    vector<int>evenSubtree1,oddSubtree1,totalEven1,totalOdd1;
    vector<int>evenSubtree2,oddSubtree2,totalEven2,totalOdd2;
    void f11(int node,int parent, vector<vector<int>>&m1){
        evenSubtree1[node]=1;
        oddSubtree1[node]=0;
        for(auto adjnode:m1[node]){
            if(adjnode!=parent){
                f11(adjnode,node,m1);
                evenSubtree1[node]+=oddSubtree1[adjnode];
                oddSubtree1[node]+=evenSubtree1[adjnode];
            }
        }
    }
    void f12(int node, int parent, vector<vector<int>>&m1,int evenAbove, int oddAbove){
        totalEven1[node]=evenSubtree1[node]+evenAbove;
        totalOdd1[node]=oddSubtree1[node]+oddAbove;
        for(auto adjnode:m1[node]){
            if(adjnode!=parent){
                int evenUp=totalOdd1[node]-evenSubtree1[adjnode];
                int oddUp=totalEven1[node]-oddSubtree1[adjnode];
                f12(adjnode,node,m1,evenUp,oddUp);
            }
        }
    }
    void f21(int node, int parent, vector<vector<int>>&m2){
        evenSubtree2[node]=1;
        oddSubtree2[node]=0;
        for(auto adjnode:m2[node]){
            if(adjnode!=parent){
                f21(adjnode,node,m2);
                evenSubtree2[node]+=oddSubtree2[adjnode];
                oddSubtree2[node]+=evenSubtree2[adjnode];
            }
        }
    }
    void f22(int node, int parent,vector<vector<int>>&m2, int evenAbove, int oddAbove){
        totalEven2[node]=evenSubtree2[node]+evenAbove;
        totalOdd2[node]=oddSubtree2[node]+oddAbove;
        for(auto adjnode:m2[node]){
            if(adjnode!=parent){
                int evenUp=totalOdd2[node]-evenSubtree2[adjnode];
                int oddUp=totalEven2[node]-oddSubtree2[adjnode];
                f22(adjnode,node,m2,evenUp,oddUp);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>m1(n),m2(m);
        for(auto i:edges1){
            int u=i[0],v=i[1];
            m1[u].push_back(v);
            m1[v].push_back(u);
        }
        for(auto i:edges2){
            int u=i[0],v=i[1];
            m2[u].push_back(v);
            m2[v].push_back(u);
        }
        evenSubtree1.resize(n);
        oddSubtree1.resize(n);
        totalEven1.resize(n);
        totalOdd1.resize(n);
        f11(0,-1,m1);
        f12(0,-1,m1,0,0);

        evenSubtree2.resize(m);
        oddSubtree2.resize(m);
        totalEven2.resize(m);
        totalOdd2.resize(m);
        f21(0,-1,m2);
        f22(0,-1,m2,0,0);

        int mxxcnt=0;
        for(int i=0; i<m; i++){
            mxxcnt=max(mxxcnt,totalOdd2[i]);
        }
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            res[i]=totalEven1[i]+mxxcnt;
        }
        return res;
    }
};
