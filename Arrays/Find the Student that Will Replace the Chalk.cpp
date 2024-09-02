//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        using ll=long long;
        int n=chalk.size();
        ll sum=accumulate(chalk.begin(),chalk.end(),0LL);
        k=k%sum;
        for(int i=0; i<n; i++){
            if(k<chalk[i]) return i;
            k-=chalk[i];
        }
        return -1;
    }
};
