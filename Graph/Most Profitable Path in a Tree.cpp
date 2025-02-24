//T.C : O(n)
//S.C : O(n)
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
struct pa{int s,d;} adjs[100000],adjs1[100000];
int pending[100000];
class Solution {
    int sz;
    void clearBob(int b,vector<int>& amount){
        int nxta,nxtb;
        for(int i=0;i<sz;++i) if(adjs1[i].d==1){
            int pre=0,cur=i;
            while(1){
                int nxt=adjs1[cur].s^pre;
                if(cur==0){nxta=nxt;break;}
                else if(cur==b){nxtb=nxt;break;}
                if(adjs1[nxt].d>2){
                    adjs1[nxt].d--;
                    adjs1[nxt].s^=cur;
                    break;
                }
                pre=cur;
                cur=nxt;
            }
        }
        int a=0,prea=0,preb=0;
        while(1){
            amount[b]=0;
            if(nxta==b) return;
            if(nxta==nxtb){amount[nxtb]>>=1;return;}
            prea=a,a=nxta,nxta=adjs1[a].s^prea;
            preb=b,b=nxtb,nxtb=adjs1[b].s^preb;
        }
    }
    void getMoney(vector<int>& amount){
        for(int i=1;i<sz;++i) if(adjs[i].d==1){
            int pre=0,cur=i;
            while(1){
                int nxt=adjs[cur].s^pre;
                pending[nxt]=max(pending[nxt],amount[cur]);
                if(nxt==0) break;
                if(adjs[nxt].d>2){
                    adjs[nxt].s^=cur;
                    adjs[nxt].d--;
                    break;
                }
                amount[nxt]+=pending[nxt];
                pre=cur;
                cur=nxt;
            }
        }
    }
public:
    int mostProfitablePath(const vector<vector<int>>& edges,int bob,vector<int>& amount) {
        sz=edges.size()+1;
        memset(adjs,0,sz*sizeof(adjs[0]));
        for(const auto &v:edges){
            adjs[v[0]].s^=v[1];
            adjs[v[0]].d++;
            adjs[v[1]].s^=v[0];
            adjs[v[1]].d++;
        }
        memcpy(adjs1,adjs,sz*sizeof(adjs[0]));
        clearBob(bob,amount);
        for(int i=0;i<sz;++i) pending[i]=INT_MIN;
        getMoney(amount);
        return amount[0]+pending[0];
    }
};
