class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                for(int k=0;k<digits.size();k++){
                    if(j==k || k==i || j==i){
                        continue;
                    }else{
                        int digit=100*digits[i]+10*digits[j]+digits[k];
                        if(digit % 2 == 0 && digits[i]!=0 && mp.find(digit)==mp.end()){
                            count++;
                            mp[digit]=1;
                        }
                    }
                }
            }
        }
        return count;
    }
};
