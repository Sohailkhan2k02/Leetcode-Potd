//T.C : O(n+m)
//S.C : O(n)
class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        int n=o.size(),m=c.size();
        unordered_set<string>st;
        for(int i=0; i<n; i++){
            st.insert(to_string(o[i][0])+'#'+to_string(o[i][1]));
        }
        int maxi=0,x=0,y=0,dir=0;
        int delrow[]={0,1,0,-1};
        int delcol[]={1,0,-1,0};
        for(int i=0; i<m; i++){
            if(c[i]==-2) dir=(dir+3)%4;
            else if(c[i]==-1) dir=(dir+1)%4;
            else{
                for(int j=0; j<c[i]; j++){
                    string pos=to_string(x+delrow[dir])+'#'+to_string(y+delcol[dir]);
                    if(st.find(pos)==st.end()){
                        x+=delrow[dir];
                        y+=delcol[dir];
                    }
                    else break;
                }
                maxi=max(maxi,x*x+y*y);
            }
        }
        return maxi;
    }
};
