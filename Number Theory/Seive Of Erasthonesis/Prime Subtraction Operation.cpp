//T.C : O(1001*log(log(1001) + n*log1001) => O(n) as others are constant
//S.C : O(1001) => O(1)
class Solution {
public:
    int primes[1001];
    vector<int>vc;
    void seive(){
        fill(primes,primes+1001,1);
        primes[0]=primes[1]=0;
        for(int i=2; i<1001; i++){
            if(primes[i]){
                for(int j=i*i; j<1001; j+=i){
                    primes[j]=0;
                }
            }
        }
        for(int i=2; i<1001; i++){
            if(primes[i]){
                vc.push_back(i);
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        seive();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]) continue;
            auto it=lower_bound(vc.begin(),vc.end(),nums[i]-nums[i+1]+1);
            if(it==vc.end()) return false;
            nums[i]-=vc[it-vc.begin()];
            if(nums[i]<=0) return false;
        }
        return true;
    }
};
