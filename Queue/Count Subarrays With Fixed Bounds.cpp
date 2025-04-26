//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // int n=nums.size();
        // int i=0,j=0;
        // long long cnt=0;
        // while(j<n){
        //     if(nums[j]>=minK && nums[j]<=maxK){
        //         cnt+=j-i+1;
        //     }
        //     else if(nums[j]<minK){
        //         i=j+1;
        //     }
        //     else{
        //         i=j+1;
        //     }
        //     j++;
        // }
        // return cnt;

        long long cnt=0;
        int n=nums.size();
        int mini=-1,maxi=-1,culp=-1;
        for(int i=0; i<n; i++){
            if(nums[i]<minK || nums[i]>maxK){
                culp=i;
            }
            if(nums[i]==minK){
                mini=i;
            }
            if(nums[i]==maxK){
                maxi=i;
            }

            long long temp=min(mini,maxi)-culp;
            if(temp>0){
                cnt+=temp;
            }
            else{
                cnt+=0; // BECAUSE IN CASE OF NEGATIVE ANSWER OR ZERO ANSWER THERE ARE NO SUBARRAYS TO BE FORMED
                // {1, 3, 2, 4, 6, 5}, int minK = 2, maxK = 5 
                // here for index 0 the temp will be min(-1,-1)-(-1)
                //-1-(-1)=0 so we add nothing
                // now for index 1 same result because nums[i] is neither minK ,nor maxK nor culp
                // cnt is 0 upto index 1
                // now for index 2 the mini will updated because mini=minK mini=2
                // now temp =min(2,-1)-(-1) =0; cnt is 0 upto index 2
                // now for index 3 the same result cnt is 0
                // now for index 4 the culp is this so culp gets updated culp=4
                // now temp=min(2,-1)-(4)=-1-4=-5 which is negative so cnt is 0 only
                // now for index 5 the maxi updated to maxi=5;
                // now temp=min(2,5)-(4)=2-4=-2 which is negative so cnt is 0
                // SO OUR RESULT IS 0 HERE 
                // THIS IS FULL CORNER CASE SCENERIO
            }
        }
        return cnt;
    }
};
