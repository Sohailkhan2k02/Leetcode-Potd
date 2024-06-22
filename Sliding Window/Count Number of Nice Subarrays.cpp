//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int f(vector<int>& v, int k){
        int i=0,j=0;
        int odd=0,ans=0;
        while(j<v.size()){
            if(v[j]%2==1) odd++;
            while(odd>k){
                if(v[i++]%2==1){
                    odd--;
                }
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& v, int k) {
        return f(v,k)-f(v,k-1);
    }
};
