class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2 == 0){
            for(int i=-n/2; i<0; i++){
                ans.push_back(i);
            }
            for(int i=1; i<=n/2; i++){
                ans.push_back(i);
            }
        } else {
            for(int i=-n/2; i<0; i++){
                ans.push_back(i);
            }
            for(int i=0; i<=n/2; i++){
                ans.push_back(i);
            }
        }


        return ans;
    }
};
