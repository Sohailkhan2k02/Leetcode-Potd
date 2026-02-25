class Solution {
public:
    int f(int n){
        int cnt=0;
        while(n!=0){
            if((n&1)==1){
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {

        auto compare=[&](int a,int b){
            int fa=f(a);
            int fb=f(b);

            if(fa==fb){
                return a<b;
            }
            return fa<fb;
        };        
        sort(arr.begin(),arr.end(), compare);
        return arr;
    }
};
