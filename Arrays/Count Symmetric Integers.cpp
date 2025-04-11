//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low;i<=high;i++){
            string arr = to_string(i);
            if(arr.size()%2 == 1) continue;
            int half = arr.size()/2;
            int sum1 = 0,sum2 = 0;
            for(int k = 0;k<half;k++) sum1+=(arr[k]-'0');
            for(int k = half;k<arr.size();k++) sum2+=(arr[k]-'0');
            if(sum1 == sum2) cnt++;
        }
        return cnt;
    }
};
