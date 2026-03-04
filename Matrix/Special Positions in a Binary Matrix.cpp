class Solution {
public:
    bool valid(int sr,int r){
        return sr<r && sr>=0 ;
    }
    bool validcolumn( int sr,int sc,vector<vector<int>>& m){
        int dr[]={-1, 1}; // up down
        int dir=0;
        int c=0;
        int str=sr;
        while(true){
            if(valid(     sr+dr[dir]  ,    m.size()    )){
                if(sr+dr[dir]!=str && m[ sr+dr[dir]][sc]==1){
                    return false;
                    
                }
                sr+=dr[dir];
            }
            else{
                dir=(dir+1)%2;
                sr=str;
                c++;
            }
            if(c==2){
                return true;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& m) {
        int ans=0;
        for(int i=0;i<m.size();i++){
            int ind=-1;
            int jnd=-1;
            int one=-1;
            int c=0;
            for(int j=0;j<m[i].size();j++){
                if(m[i][j]==1){
                    one=m[i][j];
                    ind=i;
                    jnd=j;
                    c++;
                }
            }
            if(c==1 && validcolumn(ind,jnd, m)){
                ans++;
            }
        }
        return ans;
    }
};
