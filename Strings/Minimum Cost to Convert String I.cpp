#define ll long long
class Solution {
public:
    vector<vector<ll>>cst;
    void dijsktra(unordered_map<char,vector<pair<char,int>>>&mpp,char src){
        priority_queue<pair<ll,char>,vector<pair<ll,char>>,greater<pair<ll,char>>>pq;
        // GETTING RUNTIME ERROR IN dis(n,INT_MAX) cause there are some outof bounds also
        vector<ll>dis(26,INT_MAX);
        dis[src-'a']=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            char node=pq.top().second;
            pq.pop();

            for(auto vec:mpp[node]){
                char adjnode=vec.first;
                int dist=vec.second;
                if(d+dist<dis[adjnode-'a']){
                    dis[adjnode-'a']=d+dist;
                    pq.push({d+dist,adjnode});
                }
            }
        }

        // for(auto i:dis){
        //     cout<<i<<" ";
        // }

        for(int i=0; i<26; i++){
            cst[src-'a'][i]=dis[i];
        }
    }
    long long minimumCost(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=changed.size();
        unordered_map<char,vector<pair<char,int>>>mpp;
        for(int i=0; i<n; i++){
            int u=original[i],v=changed[i],wt=cost[i];
            mpp[u].push_back({v,wt});
        }

        cst=vector<vector<ll>>(26,vector<ll>(26,INT_MAX));
        for(char ch='a'; ch<='z'; ch++){
            dijsktra(mpp,ch);
        }
        // for(auto i:cst){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // for (auto i : m) {
        //     auto u = i.first;
        //     for (auto j : i.second) {
        //         auto v = j.first;
        //         auto wt = j.second;
        //         cout << u << "->" << v << "->" << wt << " ";
        //     }
        //     cout << endl;
        // }
        ll cnt=0,i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++,j++;
            }
            else if(s[i]!=t[j]){
                // bool f=false;
                // for(auto it:m[s[i]]){
                //     cnt+=it.second;
                //     f=true;
                //     break;
                // }
                // if(!f){
                //     int mini=INT_MAX;
                //     for(auto it:m[s[i]]){
                //         mini=min(mini,it.second);
                //     }
                //     cnt+=mini;
                // }
                // i++,j++;
                ll cost=cst[s[i]-'a'][t[j]-'a'];
                if(cost==INT_MAX) return -1;
                cnt+=cost;
                i++,j++;
            }
        }     
        return cnt; 
    }
};
