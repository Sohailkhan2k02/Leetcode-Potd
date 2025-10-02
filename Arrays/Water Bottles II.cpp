class Solution {
public:
    int maxBottlesDrunk(int a, int b) {
         int tot=a;
        while(a>=b) tot+=1,a-=b-1,++b;
        return tot;
    }
};
