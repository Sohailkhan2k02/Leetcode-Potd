class Solution {
public:
    int maxDistance(string s, int k) {
        int x =0;
        int y =0;

        int ea = 0;
        int no = 0;
        int we = 0;
        int su = 0;
        int ans =0;
        for(int i =0;i<s.length();i++){
            if(s[i]=='N'){
                y = y+1;
                no++;
            }
            else if(s[i] == 'S'){
                y = y -1;
                su++;
            }
            else if(s[i] == 'E'){
                x = x + 1;
                ea++;
            }
            else if(s[i] == 'W'){
                x = x-1;
                we++;
            }
            if(x >= 0 && y >= 0){
                int p = min(k,we+su);
                int z = abs(x)+abs(y) + p*2;
                ans = max(ans,z); 
            }
            else if(x<0 && y >=0){
                int p = min(k,ea+su);
                int z = abs(x)+abs(y) + p*2;
                ans = max(ans,z);
            }
            else if(x>=0 && y<0){
                int p = min(k,no+we);
                int z = abs(x)+abs(y) + p*2;
                ans = max(ans,z);
            }
            else if(x<0 && y < 0){
                int p = min(k,no+ea);
                int z = abs(x)+abs(y) + p*2;
                ans = max(ans,z);
            }
        }
        return ans;



    }
};
