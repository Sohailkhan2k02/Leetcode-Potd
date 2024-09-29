//T.C : O(1)
//S.C : O(n)
class AllOne {
public:
    unordered_map<string,int>mpp;
    pair<string,int>maxi={"",INT_MIN},mini={"",INT_MAX};
    AllOne() {
        mpp.clear();
        mpp=unordered_map<string,int>();
    }
    
    void inc(string key) {
        mpp[key]++;
        if(maxi.second<=mpp[key]){
            maxi={key,mpp[key]};
        }
        if(mini.second>=mpp[key]){
            mini={key,mpp[key]};
        }
        else if(mini.first==key){
            int mn=INT_MAX;
            for(auto [u,f]:mpp){
                if(f<mn){
                    mini={u,f};
                    mn=f;
                }
            }
        }
    }
    
    void dec(string key) {
        mpp[key]--;
        if(mpp[key]==0){
            mpp.erase(key);
        }
        if(mpp.empty()){
            maxi={"",INT_MIN};
            mini={"",INT_MAX};
        }
        else{
            if(maxi.first==key){
                int mx=INT_MIN;
                for(auto [u,f]:mpp){
                    if(f>mx){
                        maxi={u,f};
                        mx=f;
                    }
                }
            }
            if(mini.first==key){
                int mn=INT_MAX;
                for(auto [u,f]:mpp){
                    if(f<mn){
                        mini={u,f};
                        mn=f;
                    }
                }
            }
        }
    }
    
    string getMaxKey() {
        return maxi.first;
    }
    
    string getMinKey() {
        return mini.first;
    }
};
