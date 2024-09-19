//T.C : O(n)
//S.C : O(n)
class Solution {
private:   
    int solve(int x, int y, char c){
        if(c == '+') return x+y;
        if(c == '-') return x-y;
        if(c == '*') return x*y;
        return 0;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isNum=1;
        for(int i=0; i<expression.size(); i++){
            if(!isdigit(expression[i])){
                isNum=0;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                cout<<left.size()<<" "<<right.size();
                for(auto x: left){
                    for(auto y: right){
                        ans.push_back(solve(x, y, expression[i]));
                    }
                }
            }
        }
        if(isNum) ans.push_back(stoi(expression));
        return ans;
    }
};
