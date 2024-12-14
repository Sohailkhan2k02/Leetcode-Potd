//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        using ll=long long;
        int n=nums.size();
        int i=0,j=0;
        multiset<int>st;
        ll cnt=0;
        while(j<n){
            st.insert(nums[j]);
            while(*st.rbegin()-*st.begin()>2){
                st.erase(st.find(nums[i]));
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};
