class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size() ; 
        int mx = *max_element(nums.begin(),nums.end()) ; 

        //mark all divisors
        vector<long>track(mx+1,0) ; 

        for(auto &x : nums) {
            for(int i=1 ; i*i<=x ; i++) {
                if(x%i==0) {
                    track[i]++ ; 
                    if(i!=(x/i)) track[x/i]++ ; 
                }
            }
        }

        for(int i=mx ; i>=1 ; i--) {

            long count = track[i] ; 
            track[i] = (count*(count-1))/2 ; 

            for(int mul=2*i ; mul<=mx ; mul+=i) {
                track[i] -= track[mul] ; 
            }
        }

        for(int i=1 ; i<=mx ; i++) {
            track[i] += track[i-1] ; 
        }

        vector<int>ans ; 
        for(auto &val : queries) {
            val++ ; 

            int idx = lower_bound(track.begin(),track.end(),val) - track.begin() ; 
            ans.push_back(idx) ;
        }

        return ans ; 
    }
};
