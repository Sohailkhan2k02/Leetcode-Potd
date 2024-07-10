//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        stack<string>st;
        for(int i=0; i<n; i++){
            string s=logs[i];
            if(s=="../"){
                if(!st.empty()) st.pop();
            }
            else if(s=="./"){
               continue;
            }
            else{
               st.push(s);
            }
        }

        int cnt=0;
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return cnt;
    }
};
