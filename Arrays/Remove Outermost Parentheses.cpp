class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int cnt=0;
        string res="";
        bool f=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') cnt++;
            else cnt--;

            if(cnt==1 && f==0){
                f=1;
                continue;
            }
            if(cnt==0 && f==1){
                f=0;
                continue;
            }
            res+=s[i];
        }
        return res;
        // stack<char>st;
        // int n=s.size();
        // vector<int>ind;
        // for(int i=0; i<n; i++){
        //     while(!st.empty() && st.top()=='(' && s[i]==')'){
        //         st.pop();
        //     }
        //     if(st.empty()){
        //         ind.push_back(i);
        //     }
        //     st.push(s[i]);
        // }
        // for(auto i:ind){
        //     cout<<i<<" ";
        // }
        // return "";
    }
};
