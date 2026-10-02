class Solution {
public:
    void f(int open, int close, vector<string>& ans,string res){
	// base case
        if (open == 0 && close == 0){
            ans.push_back(res);
            return;
        }

        if (open > 0){
            res.push_back('(');
            f(open-1, close, ans,res);
			// backtracking
            res.pop_back();
        }

        if (close > open){
            res.push_back(')');
            f(open, close-1, ans,res);
            //backtracking
            res.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string res = "";
        vector<string> ans;
        f(n, n, ans,res);
        return ans;
    }
};
