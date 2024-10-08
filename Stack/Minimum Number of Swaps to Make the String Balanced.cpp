// 1. Using Stack
// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        stack<char> stk;

        for(char&ch: s){
            if(ch == '[') stk.push('[');
            else if(!stk.empty()) stk.pop();
            else count++;
        }        

        return (count + 1)>>1;
    }
};

// 2. Space Optimized Greedy
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int open=0,close=0;
        for(int i=0; i<n; i++){
            if(s[i]=='['){
                open++;
            }
            else if(s[i]==']'){
                if(open>0) open--;
                else close++;
            }
        }
        return (close+1)/2;
    }
};
