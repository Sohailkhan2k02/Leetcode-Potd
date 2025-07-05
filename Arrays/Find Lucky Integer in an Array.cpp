//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {

        int x,result=-1;
        unordered_map<int,int> val;

        for(int j:arr){
            val[j]++;
        }

        for (auto& pair:val){
            if (pair.first == pair.second){
                result=max(result, pair.first);
            }
        }
        
        return result;

    }
};
