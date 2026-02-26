class Solution {
public:
    // int numSteps(string s) {
    //     int cnt = 0;
    //     while (s != "1") {
    //         if (s.back() == '0') {
    //             s.pop_back();
    //         } else {
    //             int i = s.size() - 1;
    //             while (i >= 0 && s[i] == '1') {
    //                 s[i] = '0';
    //                 i--;
    //             }
    //             if (i < 0) {
    //                 s = '1' + s;
    //             } else {
    //                 s[i] = '1';
    //             }
    //         }
    //         cnt++;
    //     }
    //     return cnt;
    // }

    int numSteps(string s){
        int n=s.size();
        int cnt=0,carry=0;
        for(int i=n-1; i>=1; i--){
            if((s[i]-'0'+carry)%2==1){
                cnt+=2;
                carry=1;
            }
            else{
                cnt+=1;
            }
        }
        return cnt+carry;
    }
};
