class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>a,b;
        for(int i=0; i<n; i++){
            if(i==0) a.push_back(nums[i]);
            else if(i==1) b.push_back(nums[i]);
            else if(a.back()>b.back()) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        for(int i=0; i<a.size(); i++){
            cout<<a[i];
        }
        cout<<endl;
        for(int i=0; i<b.size(); i++){
            cout<<b[i];
        }
        cout<<endl;
        for(auto i:b){
            a.push_back(i);
        }
        return a;
    }
};
