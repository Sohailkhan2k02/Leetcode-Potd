class Solution {
public:
  static const long long LIMIT = 1000001;

    long long nCr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIMIT) return LIMIT;
        }
        return ans;
    }


    long long  countways(vector<int>&nums){
        int total = 0 ;
        for(auto it : nums){
            total +=it;
        }
        long long ans = 1;
        int rem = total;
        for(int x : nums){
            if(x ==0) continue;
            ans *= nCr(rem , x);
            if(ans >= LIMIT){
                ans = LIMIT;
            }
            rem -=x;
        }
        return ans;

    }



    string smallestPalindrome(string s, int k) {
        // step 1 ; count the frequency of every character in the string: 
        vector<int> freq(26);
        for (char c : s){
            freq[c - 'a']++;
        }
        vector<int>half(26);
        string mid = "";
        for(int i = 0 ;i < 26 ;i++){
            half[i] = freq[i]/2;
            if(freq[i] %2 !=0){
                mid.push_back(char('a' + i));
            }
        }

        if(countways(half) <  k ){ // means the number of permutaions are less than the required;
            return "";
        }

        int len = 0 ;
        for(auto it : half){
            len += it;
        }

        // start greedily : - 
        string left;
        for (int pos = 0 ; pos < len; pos++) {
             for(int c = 0 ; c < 26 ; c++){
                if(half[c] ==0){
                    continue;
                }
                half[c]--;
                long long  cnt = countways(half);
                if(cnt  >= k){
                    left += char('a' + c);
                    break;
                }else{
                    k -=cnt;
                    half[c]++; // restore it if rejected : 
                }
             }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;

    }
};
