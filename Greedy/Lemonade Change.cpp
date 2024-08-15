class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int n=b.size();
        int c1=0,c2=0,c3=0;
        for(int i=0; i<n; i++){
            if(b[i]==5){c1++;}
            if(b[i]==10){c2++;
                if(c1>0){c1--;}
                else return false;
            }
            if(b[i]==20){
                if(c1>0 && c2>0){c2--;c1--;}
                else if(c1>=3){c1-=3;}
                else return false;
            }
        }
        return true;
    }
};
