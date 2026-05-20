class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>res(n);
        unordered_set<int>st;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(st.find(A[i])!=st.end()) cnt++;
            else st.insert(A[i]);
            if(st.find(B[i])!=st.end()) cnt++;
            else st.insert(B[i]);
            res[i]=cnt;
        }
        return res;
    }
};
