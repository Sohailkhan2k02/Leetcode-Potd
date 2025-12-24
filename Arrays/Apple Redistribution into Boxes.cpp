class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int t=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int cnt=0;
        for(auto i:capacity){
            t-=i;
            cnt++;
            if(t<=0){
                return cnt;
            }
        }
        return cnt;
    }
};
