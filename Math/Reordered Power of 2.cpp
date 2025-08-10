class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> mp(10,0);
        while(n>0)
        {
            int rem = n%10;
            mp[rem]+=1;
            n/=10;
        }
        int temp = 0;
        for(int i=0;i<32;++i)
        {
            temp = (1<<i);
            vector<int> powmp(10,0);
            int x = temp;
            while(x>0)
            {
                powmp[x%10]+=1;
                x/=10;
            }
            if(mp == powmp) return true;
        }
        return false;
    }
};
