//T.C : O(n*2^n)
//S.C : O(n)
class Solution {
public:
    // HERE WE ARE CHOOSING OPTIONS LIKE SUPPOSE FIRST WE HAVE TO SORT IT
    // BECAUSE THEY WANT IN SORTED ORDER AND WE CAN CHOOSE FROM ANY INDEX
    // FOR EG [1,1,1,2,3,4,4,5,5,5] WE CAN CHOOSE INDEX 0,1,2,3,4,5,6,7 ANYTHING
    // BUT WE HAVE TO SATISFY Each number in candidates may only be used once in the combination. THIS CONDITION ALSO
    // SO SUPPOSE WE GO BY CHOOSING INDEX 0 THEN WE CANT CHOOSE INDEXES 1 AND 2
    // WHY BECAUSE THEY ARE SAME [1,1,1] SO HERES HOW U REMOVE DUPLICATES
    // HOW WE CHOOSE BY IF(CANDIDATES[I]==CANDIDATES[I-1]) CONTINUE;
    // NOW ONE CRUCIAL PART IS SUPPOSE WE HAVE CHOSEN INDEX 0 AND IN DS [1]
    // NOW WE MOVE FURTHER IN THE TREE AND AT INDEX 1 THERE IS AGAIN 1 BUT 
    // IF CONDITION SPECIFIES THAT WE CANT CHOOSE IT BUT THAT CAN BE CHOOSEN BECAUSE
    // WE HAVE TAKEN I+1 RECURSIVE CALL SO WE HAVE TO SPECIFY ONE MORE CONDITION
    // IF(I>IND && CANDIDATES[I]==CANDIDATES[I-1]) THEN ONLY CONTINUE OTHERWISE TAKE IT

    // FUN FACT WHY WE HAVENT TAKEN BASE CONDITION AS IF(I==N)
    // IS BECAUSE WE CAN CHOOSE ANY INDEXES AT FIRST STEP SO IF I CHOOSE INDEX ==N
    // OUR DS WILL ALWAYS BE EMPTY AND IT WILL RETURN AND THIS IS WRONG FOR THE CASES
    // WHERE ANY INDEXES FROM 0 TO N CAN BE CHOOSEN AT FIRST
    // THE BASE CASE CANT BE OF OUT OF BOUNDS CASE

    void f(int ind, int target, vector<int>&candidates, vector<int>&ds, vector<vector<int>>&res){
        int n=candidates.size();
        if(target==0){
            res.push_back(ds);
            return;
        }

        for(int i=ind; i<n; i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(target-candidates[i]>=0){
                ds.push_back(candidates[i]);
                f(i+1,target-candidates[i],candidates,ds,res);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>res;
        f(0,target,candidates,ds,res);
        return res;
    }
};
