//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        map<int,int>mpp;
        int n=s.size();
        for(auto i:shifts){
            int start=i[0],end=i[1],d=i[2];
            if(d==0){
                mpp[start]--;
                mpp[end+1]++;
            }
            else{
                mpp[start]++;
                mpp[end+1]--;
            }
        }
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=mpp[i];
            while(sum<0) sum+=26;
            int shift=((s[i]-'a')+sum)%26;
            s[i]='a'+shift;
        }
        return s;
    }
};
