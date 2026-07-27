class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
            if(pq.size()>2){
                pq.pop();
            }
        }
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            return (a-1)*(b-1);
        }
        return -1;
    }
};
