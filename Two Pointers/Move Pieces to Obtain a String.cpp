//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int l=0,r=0;
        for(int i=0; i<n; i++){
            if(start[i]=='R'){
                r++;
                if(l!=0) return false;
            }
            else if(start[i]=='L'){
                l--;
            }
            if(target[i]=='R'){
                r--;
            }
            else if(target[i]=='L'){
                l++;
                if(r!=0) return false;
            }
            if(l<0 || r<0) return false;
        }
        return l==0 && r==0;
    }
};
