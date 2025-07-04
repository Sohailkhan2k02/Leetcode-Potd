//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    using ll=long long;
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        // now binary form of k
        string s="";
        ll num=k;
        while(num>0){
            if(num&1){
                s+='1';
            }
            else s+='0';
            num=num/2;
        }
        ll cnt=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1' && operations[i]==1){
                cnt++;
            }
        }
        return 'a'+(cnt)%26;
    }
};
