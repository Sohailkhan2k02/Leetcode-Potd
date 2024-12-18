//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>st;
        st.push(n-1);
        vector<int>res(n,0);
        res[n-1]=prices[n-1];
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && prices[st.top()]>prices[i]){
                st.pop();
            }
            if(!st.empty() && prices[st.top()]<=prices[i]){
                res[i]=abs(prices[st.top()]-prices[i]);
            }
            else{
                res[i]=prices[i];
            }
            st.push(i);
        }
        return res;
    }
};
