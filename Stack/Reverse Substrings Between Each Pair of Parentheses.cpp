//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open; //You can use a vector also as stack
        string res;
        for (char c : s) {
            if (c == '(') {
                open.push(res.size());
            } else if (c == ')') {
                int start = open.top();
                open.pop();
                reverse(res.begin() + start, res.end());
            } else {
                res += c;
            }
        }
        return res;
    }
};


//Approach-2 (Linear Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        int direction = 1; //Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};
