class Solution {
public:
    bool checkFirst(int c)
    {
        if(c>=2 && c<=5) return false;
        else return true;
    }
    bool checkSec(int c)
    {
        if(c>=4 && c<=7) return false;
        else return true;
    }
    bool checkThird(int c)
    {
        if(c>=6 && c<=9) return false;
        else return true;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        sort(reservedSeats.begin(),reservedSeats.end());
        int tot=0,r=1;
        bool first=true,sec=true,trd=true;
        for(int i=0;i<m;i++)
        {
            int row=reservedSeats[i][0];
            int col=reservedSeats[i][1];
            if(r!=row)
            {
                if(first && trd) tot+=2;
                else if(first) tot++;
                else if(sec) tot++;
                else if(trd) tot++;
                tot+=(row-r-1)*2;
                r=row;
                first=true,sec=true,trd=true;
            }
            if(first && checkFirst(col)==false) first=false;
            if(sec && checkSec(col)==false) sec=false;
            if(trd && checkThird(col)==false) trd=false;
        }
        if(first && trd) tot+=2;
        else if(first) tot++;
        else if(sec) tot++;
        else if(trd) tot++;
        tot=tot+(n-r)*2;
        return tot;
    }
};
