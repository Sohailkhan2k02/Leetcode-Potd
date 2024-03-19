// T.C: O(nlogn + n * (n + 1) * logn)
// S.C: O(n)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt=0;
        priority_queue<int>pq;
        vector<int>mpp(26,0);
        for(char &c:tasks){
            mpp[c-'A']++;
        }
        for(int i=0; i<mpp.size(); i++){
            if(mpp[i]>0){
                pq.push(mpp[i]);
            }
        }

        while(!pq.empty()){
            vector<int>temp;
            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto i:temp){
                if(i>0){
                    pq.push(i);
                }
            }

            if(pq.empty()){
                cnt+=temp.size();
            }
            else{
                cnt+=n+1;
            }
        }
        return cnt;
    }
};
