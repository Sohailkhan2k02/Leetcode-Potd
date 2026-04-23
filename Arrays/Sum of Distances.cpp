class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<long long>>left,right;
        int n = nums.size();
        vector<long long>vleft(n,0), vright(n,0);
        for(int i=0;i<n;i++){
            int value = nums[i];
            if(left.find(value)==left.end()){
                vleft[i] = 0;
                left[value] = {1,i,0};
            }else{
                long long no_of_values = left[value][0];
                long long prev_ind= left[value][1];
                long long prev_sum = left[value][2];
                vleft[i] = prev_sum + no_of_values*(abs(i-prev_ind));
                left[value] = {no_of_values+1, i, vleft[i]};
            }
        }
        for(int i=n-1;i>=0;i--){
            int value = nums[i];
            if(right.find(value)==right.end()){
                vright[i] = 0;
                right[value] = {1,i,0};
            }else{
                long long no_of_values = right[value][0];
                long long prev_ind= right[value][1];
                long long prev_sum = right[value][2];
                vright[i] = prev_sum + no_of_values*(abs(i-prev_ind));
                right[value] = {no_of_values+1, i, vright[i]};
            }
        }
        vector<long long>ans;
        for(int i=0;i<n;i++){
            ans.push_back(vleft[i]+vright[i]);
        }
        return ans;
    }
};
