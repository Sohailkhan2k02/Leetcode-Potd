class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for(int i = 1;i<num.size() - 1;i++){
            if(num[i-1] == num[i] and num[i] == num[i+1]){
                string integer = string(3, num[i]);
                ans = max(ans, integer);
            }
        }
        return ans;
    }
};
