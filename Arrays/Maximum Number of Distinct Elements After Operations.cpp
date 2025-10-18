class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        //ASSIGN THE SMALLEST VALUES IN THE RANGE OF -K TO K AFTER SORTING
        // STARTING FROM 0 TO N
        // [1,2,2,3,3,7]
        //  RANGE FOR EACH ELEMENT
        // 1->-1 TO 3
        // 2->0 TO 4
        // 2->0 TO 4
        // 3->1 TO 5
        // 3->1 TO 5
        // 7->5 TO 9
        // NOW IF WE WANT TO MAXIMISE THE NUMBER OF DISTINCT ELEMENTS SO WE HAVE MINIMISE THE RANGE OF FIRST NUMBER SO THAT SECOND NUMBER HAVE THE HIGHER LIBERTY OF CHOOSING FROM THE RANGE
        // SO FOR 1 THE MINIMUM CAN BE -1 NOW WE WILL CHECK FOR 2 BY INCREASING JUST +1
        // -1 + 1 =0 AND IT IS IN THE RANGE OF 2 ->0 TO 4 AND WHY WE ARE INCREASING 1 BY 1 BECAUSE WE WANT TO MAKE THE MAX DISTINCT ELEMENTS
        // NOW [-1,0] NOW FOR 2 WE WILL INCREASE +1 IN OUR PREV VAL =0+1=1 IS IN RANGE OF 2->0 TO 4 SO NOW [-1,0,1] 
        // NOW FOR 3 -> 1+1=2 IN THE RANGE SO [-1,0,1,2]
        // NOW FOR 3 ->2+1 IN THE RANGE SO [-1,0,1,2,3]
        // NOW FOR 7 ->3+1 =4 IT IS LESS THAN THE LOWERBOUND OF 7 WHICH IS 5 SO 
        // WE WILL JUST ASSIGN THE LOWERBOUND TO 7 SO THAT FOR NEXT ELEMENTS SHOULD
        // GET HIGHER PRIORITY
        // [-1,0,1,2,3,5]
        // AND THIS WILL BE OUR ANS 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0,prev=INT_MIN;
        for(int i=0; i<n; i++){
            int leftRange=nums[i]-k;
            int rightRange=nums[i]+k;
            if(prev<leftRange){
                prev=leftRange;
                cnt++;
            }
            else if(prev<rightRange){
                prev++;
                cnt++;
            }
        }
        return cnt;
    }
};
