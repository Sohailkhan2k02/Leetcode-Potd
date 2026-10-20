class Solution {
public:
  bool check(vector<int>& arr , int l , int r){
      int val = 0;

      for(int i=l ; i<r ; i++){
          if(arr[i] > arr[i+1]) val++;
      }
      if(arr[r] > arr[l]) val++;

      return val <= 1;
  }

  int sortableIntegers(vector<int>& nums) {
      int n = nums.size();

      vector<int> divs;

      // find divisors of n
      for(int i=1 ; i*i <= n ; i++){
          if(n % i == 0){
              divs.push_back(i);
              if(i != n/i) divs.push_back(n/i);
          }
      }

      sort(divs.begin() , divs.end());

      int ans = 0;

      for(int i=0 ; i<divs.size() ; i++){
          int k = divs[i];

          vector<int> mins , maxs;
          bool ok = 1;

          // process each block
          for(int j=0 ; j<n ; j+=k){
              int l = j;
              int r = j+k-1;

              if(!check(nums , l , r)){
                  ok = 0;
                  break;
              }

              int mini = 1e9;
              int maxi = -1;

              for(int t=l ; t<=r ; t++){
                  mini = min(mini , nums[t]);
                  maxi = max(maxi , nums[t]);
              }

              mins.push_back(mini);
              maxs.push_back(maxi);
          }

          if(!ok) continue;

          // check ordering between blocks
          for(int i=1 ; i<mins.size() ; i++){
              if(maxs[i-1] > mins[i]){
                  ok = 0;
                  break;
              }
          }

          if(ok) ans += k;
      }

      return ans;
  }
};
