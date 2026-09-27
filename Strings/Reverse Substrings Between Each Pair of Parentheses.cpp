class Solution {
public:
//     string reverseParentheses(string s) {
//         int n=s.size();
//         vector<int>open;
//         string res="";
//         for(int i=0; i<n; i++){
//             if(s[i]=='('){
//                 open.push_back(res.size());
//             }
//             else if(s[i]==')'){
//                 int j=open.back();
//                 open.pop_back();
//                 reverse(res.begin()+j,res.end());
//             }
//             else{
//                 res+=s[i];
//             }
//         }
//         return res;
//     }
    string reverseParentheses(string s) {
        int n=s.size();
        stack<string>st;
        string res="";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(res);
                res="";
            }
            else if(s[i]==')'){
                reverse(res.begin(),res.end());
                if(!st.empty()){
                    res=st.top()+res;
                    st.pop();
                }
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
