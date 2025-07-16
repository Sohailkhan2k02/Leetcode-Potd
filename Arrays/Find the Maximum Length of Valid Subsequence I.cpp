class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int c1=0,c2=0,c3=0,flag=-1;
        for(auto i:nums){
            if(i%2==0){
                c1++;
                if(flag!=0){
                    c3++;
                    flag=0;
                }
            }
            else{
                c2++;
                if(flag!=1){
                    c3++;
                    flag=1;
                }
            }
        }
        return max({c1,c2,c3});
    }
};
