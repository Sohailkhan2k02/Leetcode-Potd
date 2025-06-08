class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        // for(int i=1; i<=n; i++){
        //     res.push_back(i);
        // }
        // sort(res.begin(),res.end(),[&](int a, int b){
        //     return to_string(a)<to_string(b);
        // });
        // return res;
        int curr =1;
        while (res.size() < n){
            res.push_back(curr);
            if (curr * 10<=n){
                curr *= 10;
            }else{
                while (curr % 10==9 || curr == n)
                curr /= 10;
                ++curr;
            }
        }
        return res;
    }
};
