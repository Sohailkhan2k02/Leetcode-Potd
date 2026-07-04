class Solution {
public:
    vector<int> parent,rnk;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int xpar=find(x);
        int ypar=find(y);
        if(rnk[xpar]>rnk[ypar]) parent[ypar]=xpar;
        else if(rnk[xpar]<rnk[ypar]) parent[xpar]=ypar;
        else{
            parent[ypar]=xpar;
            rnk[xpar]++;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        rnk.resize(n+1,0);
        for(int i=0;i<n+1;i++) parent[i]=i;

        for(auto &ele: roads){
            if(find(ele[0])!=find(ele[1])) Union(ele[0],ele[1]);
        }
        int minRoad=INT_MAX;
        for(auto &ele: roads){
            if(find(1)!=find(ele[0]) or find(1)!=find(ele[1])) continue;
            minRoad=min(minRoad,ele[2]);
        }
        return minRoad;
    }
};
