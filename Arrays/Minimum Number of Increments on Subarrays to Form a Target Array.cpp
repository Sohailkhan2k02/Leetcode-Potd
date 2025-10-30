class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int prev=0,cnt=0;
        for(int i=0; i<n; i++){
            int curr=target[i];
            if(curr>prev){
                cnt+=curr-prev;
            }
            prev=curr;
        }
        return cnt;
    }
};
