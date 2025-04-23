//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        int maxi=0;
        for(int i=1; i<=n;i++){
            int cnt=0,x=i;
            while(x>0){
                cnt+=x%10;
                x/=10;
            }
            // cout<<cnt<<" ";
            mpp[cnt]++;
            maxi=max(maxi,mpp[cnt]);
            // cout<<mpp[cnt];
        }
        int cnt=0;
        for(auto i:mpp){
            if(i.second==maxi) cnt++;
        }
        return cnt;
    }
};
