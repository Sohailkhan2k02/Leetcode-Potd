//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool check(vector<int> v, int k){
        for(int i=0; i<v.size(); i++) if(v[i] < k) return false; 
        return true; 
    }

    int takeCharacters(string s, int k) {
        vector<int> v(3, 0), temp(3, 0); 
        for(int i=0; i<s.length(); i++) v[s[i] - 'a']++; 
        temp = v; 
        int l = s.length()-1, r =0 ;
        int ans = INT_MAX; 
        if(!check(v, k)) return -1;
        ans = s.length();  

       while (l >= 0){
           v[s[l] - 'a']--; l--; 
           if(!check(v, k)){ 
              char kk = s[l+1]; 
              while(v[kk - 'a'] < k) {
                  v[s[s.length() -1 -r] - 'a']++; r++; 
              }
               
            }
           int t = 0; 
           t += l+1; t += r; 
        //    cout << v[0] << " " << v[1] << " " << v[2] << " " << l << "  " << r << "  " << t ; 
           if( ans > t) ans = t; 
       }

       return ans; 

        
    return ans; 



    }
};
