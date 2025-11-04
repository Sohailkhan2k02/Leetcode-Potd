class Solution {
public:
    int Xsum(vector<int>nums,int start,int end,int x){
        unordered_map<int,int>frq;
        for(int i=start;i<end;i++){
            frq[nums[i]]++;
        }
        int sum=0;
        vector<pair<int,int>>count(frq.begin(),frq.end());
        
        //sorting a vector in descending order
        //sort(nums.begin(),nums.end(),greater<int>())
        //sorting a pair vector
        sort(count.begin(),count.end(),[](auto &a,auto &b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second>b.second;
        });
         for(int i=0;i<x &&i<count.size();i++){
            sum+= count[i].first*count[i].second;
         }
           
    return sum;
        
    }
    
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>answer(n-k+1);
        
        int i=0;
        while(i+k<=n){
           answer[i]= Xsum(nums,i,i+k,x);
           i++;
        }
        return answer;
    }
};
