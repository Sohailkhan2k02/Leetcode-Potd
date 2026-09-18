class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>first(26,n),last(26,-1);
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            first[c]=min(first[c],i);
            last[c]=i;
        }
        vector<pair<int,int>>v;
        for(int c=0;c<26;c++){
            if(last[c]==-1)continue;
            int l=first[c],r=last[c];
            bool ok=true;
            for(int i=l;i<=r;i++){
                int d=s[i]-'a';
                if(first[d]<l){
                    ok=false;
                    break;
                }
                r=max(r,last[d]);
            }
            if(ok)v.push_back({r,l});
        }
        sort(v.begin(),v.end());

        vector<string>ans;
        int r=-1;
        for(auto &[nr,l]:v){
            if(l>r){
                ans.push_back(s.substr(l,nr-l+1));
                r=nr;
            }
        }
        return ans;
    }
};
