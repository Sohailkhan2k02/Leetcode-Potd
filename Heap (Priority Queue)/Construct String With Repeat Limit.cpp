//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<char>pq;
        map<char,int>mpp;
        sort(s.rbegin(),s.rend());
        for(auto i:s){
            mpp[i]++;
        }
        for(auto [u,f]:mpp){
            pq.push(u);
        }
        string res="";
        while(!pq.empty()){
            char val=pq.top();
            pq.pop();
            int cnt=min(mpp[val],repeatLimit);
            res.append(cnt,val);
            mpp[val]-=cnt;

            if(mpp[val]>0){
                if(pq.empty()) break;
                char next=pq.top();
                pq.pop();

                res+=next;
                mpp[next]--;
                if(mpp[next]>0) pq.push(next);
                pq.push(val);
            }
        }
        return res;
    }
};
