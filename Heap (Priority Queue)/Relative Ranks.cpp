//T.C : O(n*log(n))
//S.C : O(n)
class Solution {
private:
    int getIndex(vector<int>& score, int k){
        int index;
        auto it = find(score.begin(), score.end(), k);

        if(it != score.end()){
            index = it - score.begin();
        }
        return index;
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<int>pq;
        int rank = 1;

        for(int i=0 ; i<n ; i++){
            pq.push(score[i]);
        }

        vector<int> classification(n);

        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            int idx = getIndex(score, temp);
            classification[idx] = rank;
            rank++;
        }

        vector<string> ans(n);

        for(int i=0 ; i<n ; i++){
            if(classification[i] == 1){
                ans[i] = "Gold Medal";
            }
            else if(classification[i] == 2){
                ans[i] = "Silver Medal";
            }
            else if(classification[i] == 3){
                ans[i] = "Bronze Medal";
            }
            else{
                ans[i] = to_string(classification[i]);
            }
        }
        return ans;
    }
};
