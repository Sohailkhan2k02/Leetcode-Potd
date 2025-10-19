class Solution {
public:
    void dfs(set<string>& st, int a, int b, string s, int n) {
        string s1 = s, s2 = s;
        for( int i = 1; i < n; i+=2 ) {
            s1[i] = ((s1[i]-'0'+a) % 10) + '0';
        }
        for( int i = 0; i < n; ++i ) {
            s2[(i+b)%n] = s[i];
        }

        if(st.find(s1) == st.end()) {
            st.insert(s1);
            dfs(st, a, b, s1, n);
        }
        if(st.find(s2) == st.end()) {
            st.insert(s2);
            dfs(st, a, b, s2, n);
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        set<string> st;
        dfs(st, a, b, s, (int)s.size());
        return *st.begin();
    }
};
