//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();

        if(n<k)
        {
            return false;
        }

        if(n==k)
        {
            return true;
        }


        unordered_map<char,int>map;

        int count=0;

        for(auto it:s)
        {
            map[it]++;
        }



        for(auto it:map)
        {
            if(it.second%2==1)
            {
                count++;
            }
        }

        if(count>k)
        {
            return false;
        }


        return true;
    }
};
