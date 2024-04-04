//Approach-1 (using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;

        stack<char> st;
        
        for (char& ch : s) {
            
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }
            
            result = max(result, (int)st.size());
        }
        
        return result;
    }
};


//Approach-2 (using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int openBrackets = 0;

        for (char &ch : s) {
            if (ch == '(') {
                openBrackets++;
            } else if (ch == ')') {
                openBrackets--;
            }
            
            result = max(result, openBrackets);
        }
        
        return result;
    }
};
