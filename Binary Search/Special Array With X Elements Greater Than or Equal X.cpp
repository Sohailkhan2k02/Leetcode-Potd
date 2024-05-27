//T.C : O9nlogn)
//S.C : O(1)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int len=-1;
        int cnt=0;
        for(int i=0; i<=n; i++){
            int ind=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            cout<<ind<<" ";
            if(i==n-ind){
                len=max(len,n-ind);
            }
        }
        return len;
    }
};
