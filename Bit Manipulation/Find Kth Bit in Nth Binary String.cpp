class Solution {
public:
    //T.C : O(n)
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int len=(1<<n)-1;
        if(k<ceil(len/2.0)){
            return findKthBit(n-1,k);
        }
        else if(k==ceil(len/2.0)){
            return '1';
        }
        else{
            char res=findKthBit(n-1,len-k+1);
            res^=1;
            return res;
        }
    }
};
