//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s; 
        int i = 0;
        bool sol;
        int exp = 0;

        // Iterate through each character in the expression
        while (i < expression.size()) {
            char c = expression[i];
            // Push operators and operands onto the stack
            if (c == '(' || c == '!' || c == '|' || c == '&' || c == 'f' || c == 't') {
                s.push(c);
            }
            else if (c == ')') {
                vector<bool> ans;
                // Pop elements until '(' is found, collecting boolean values
                while (s.top() != '(') {
                    if (s.top() == 'f') {
                        ans.push_back(false);
                    }
                    else if (s.top() == 't') {
                        ans.push_back(true);
                    }
                    s.pop();
                }
                // Handle the first boolean value for initial setup
                if (exp == 0) {
                    sol = ans[0];
                    exp++;
                }
                s.pop(); // Remove the '('
                if (s.empty()) break;
                char op = s.top();
                s.pop();
                // Evaluate based on the operator
                if (op == '&') {
                    for (auto i : ans) {
                        sol &= i;
                    }
                }
                else if (op == '!') { 
                    sol = !ans[0]; 
                }
                else if (op == '|') {
                    for (auto i : ans) {
                        sol |= i;
                    }
                }
                // Push the result back onto the stack
                s.push(sol ? 't' : 'f');
            }
            i++;
        } 
        return sol;
    }
};
