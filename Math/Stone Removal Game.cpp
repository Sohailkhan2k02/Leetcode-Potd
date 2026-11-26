class Solution {
public:
    bool canAliceWin(int n) {
        int c=10;
        bool f=true;
        while(n>=c){
            n-=c;
            c--;
            f=!f;
        }
        return !f;
    }
};
