//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    // HERE FOR EACH INDEX WE WILL FIND ITS LONGEST INCREASING SUBSEQUENCE AND LONGEST DECREASING SUBSEQUENCE
    // [2,1,1,5,6,2,3,1]
    // LIS TABLE WILL BE - [1,1,1,2,3,2,2,1]
    // LDS TABLE WILL BE - [2,1,1,3,3,2,2,1]
    // NOW WE HAVE GOT MAX LIS AND MAX LDS FOR EACH INDEX 
    // TOTAL ELEMENTS AT INDEX I ARE =I+1
    // AND LIS IS LIS[I] NOW THE COUNT TO BE REMOVED ARE = ELEMENTS-LIS[I]
    // WHICH IS COUNT = (I+1)-LIS[I];
    // FOR LDS COUNT TOTAL ELEMENTS AT INDEX I ARE=N-I 
    // AND LDS IS LDS[I] NOW THE COUNT TO BE REMOVED ARE =ELEMENTS-LDS[I]
    // WHICH IS COUNT =(N-I)-LDS[I];

    // NOW TOTAL IS = (I+1)-LIS[I]+N-I-LDS[I];
    // TOTAL IS = N-LIS[I]-LDS[I]+1;
    // NOW WE WILL DO DRY RUN
    // [2,1,1,5,6,2,3,1]
    // LIS TABLE WILL BE - [1,1,1,2,3,2,2,1]
    // LDS TABLE WILL BE - [2,1,1,3,3,2,2,1]
    // FOR INDEX =0, N IS 8
    // LIS[I] IS = 1 LDS[I] IS = 2
    // SO COUNT = 8-1-2+1= 8-2=6
    // FOR INDEX =1, N IS 8
    // LIS[I] IS =1 AND LDS[I] IS =1
    // SO COUNT = 8-1-1+1=7
    // AND SO ON
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>LIS(n,1);
        vector<int>LDS(n,1);
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]){
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i]>nums[j]){
                    LDS[i]=max(LDS[i],LDS[j]+1);
                }
            }
        }

        int mini=n;
        for(int i=0; i<n; i++){
            if(LIS[i]>1 && LDS[i]>1){
                // BECAUSE FOR A MOUNTAIN ARRAY THE LENGTH SHOULD BE >=3 
                // AND THE LIS STORES ALL INCREASING SUBSEQUENCE SO TO REMOVE ONE LENGTH
                // FROM LIS AND LDS WE WILL USE THIS IF CASE
                mini=min(mini,n-LIS[i]-LDS[i]+1);
            }
        }
        return mini;
    }
};
