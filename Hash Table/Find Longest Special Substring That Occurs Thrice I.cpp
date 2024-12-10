//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        if(n<3) return -1;
        map<string,int>mpp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=n; j++){
                string sub=s.substr(i,j-i);
                mpp[sub]++;
            }
        }

        int len=-1;
        for(auto &[key,cnt]:mpp){
            if(cnt>=3){
                set<char>st;
                for(int j=0; j<key.size(); j++){
                    st.insert(key[j]);
                }
                if(st.size()==1){
                    len=max(len,(int)key.size());
                }
            }
        }
        return len;
    }
};
