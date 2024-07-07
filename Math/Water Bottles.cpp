//T.C : O(lognumExchange(numBottles))
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = 0 ;
        int left = 0 ;
        while(1){
            answer = answer + numBottles ;
            left = left + numBottles ;
            numBottles = left / numExchange ;
            left = left % numExchange ;
            if(numBottles == 0){
                break;
            }
        }
        return answer ;
    }
};
