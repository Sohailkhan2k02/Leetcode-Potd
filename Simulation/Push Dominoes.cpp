//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string pushDominoes(string s) 
    {
        int n=s.size();
        vector<int>val(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]!='.')
               val[i]=(s[i]=='R')?1:-1;
            else if(i>0)
            {
                if(val[i-1]>0)
                   val[i]=val[i-1]+1;
            }   
        }
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='.')
            {
                if(val[i+1]<0)
                {
                    int curr=abs(val[i+1]-1);
                    if(val[i]==0 || curr<val[i])
                        val[i]=-1*curr;
                    else if(val[i]==curr)
                        val[i]=0;        
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(val[i]>0)
                s[i]='R';
            else if(val[i]<0)
                s[i]='L';
            else
                 s[i]='.';        
        }
        return s;
    }
};
