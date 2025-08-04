class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,n=fruits.size(),maxf=0;
        unordered_map<int,int>count_fruits;

        while(j<n){
            count_fruits[fruits[j]]++;
            while(i<=j and count_fruits.size()>2){
                count_fruits[fruits[i]]--;
                if(count_fruits[fruits[i]]==0){
                    count_fruits.erase(fruits[i]);
                }
                i++;    
            }            

            maxf=max(maxf,j-i+1);
            j++;
        }
        return maxf;
    }
};
