constexpr int N=1e5;
int st[N], top=-1;
class Solution {
public:
    static int minOperations(vector<int>& nums) {
        top=-1;// reset the stack
        int op=0;
        for (int x : nums){
            while(top!=-1 && x<st[top]) top--;
            if (top==-1 || x>st[top]){
                if (x>0) op++;
                st[++top]=x;
            }
        }
        return op;
    }
};
