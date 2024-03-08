// T.C: O(n)
// S.C: O(n)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        int maxi=INT_MIN;
        int cnt=0;
        for(auto i:mpp){
            if(i.second>maxi){
                maxi=i.second;
            }
        }
        cout<<maxi<<endl;
        for(auto i:mpp){
            if(maxi==i.second){
                cnt+=i.second;
                // cnt=cnt*maxi;
            }
        }
        return cnt;
    }
};
