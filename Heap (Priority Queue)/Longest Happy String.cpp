//T.C : O(a+b+c)
//S.C : O(1)
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        string res="";
        while(!pq.empty()){
            auto [f1,ch1]=pq.top(); pq.pop();
            if(res.size()==0 || res.back()!=ch1){
                for(int i=0; i<min(2,f1); i++){
                    res+=ch1;
                }
                if(f1-2>0){
                    pq.push({f1-2,ch1});
                }
            }
            else{
                if(pq.size()==0) break;
                auto [f2,ch2]=pq.top(); pq.pop();
                for(int i=0; i<1; i++){
                    res+=ch2;
                }
                if(f2-1>0){
                    pq.push({f2-1,ch2});
                }
                pq.push({f1,ch1});
            }
        }
        return res;
    }
};
