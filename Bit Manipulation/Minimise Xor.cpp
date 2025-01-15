//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        for(int i=0; i<32; i++){
            if((num2>>i &1)!=0) cnt++;
        }
        unsigned int res{0};
        for(int i=31; i>=0; i--){
            if(cnt>0 && (num1>>i &1)!=0){
                res=res|(1<<i);
                cnt--;
            }
        }
        if(cnt>0){
            for(int i=0; i<32; i++){
                if(cnt>0 && (num1>>i &1)==0){
                    res=res|(1<<i);
                    cnt--;
                }
            }
        }
        return res;
    }
};
