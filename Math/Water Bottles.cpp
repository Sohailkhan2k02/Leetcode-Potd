//APPROACH -1
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int n1, int n2) {
        return n1+(n1-1)/(n2-1);
    }
};

//APPROACH -2
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
