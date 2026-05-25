class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size() ; 
        vector<int>arr(n+1,0) ; 
        int x = 0 ; 
        for ( int i = 0 ; i < n; i ++ ){
            x += arr[i] ; 
            if ( (s[i] == '0' && x > 0 ) || ( i == 0 )) {
                if ( i == n -1 ) return true ;
                int l = i + minJump ; int r = min ( i + maxJump , n-1 ) ; 
                if ( l < n && r < n && l <= r ) { arr[l]++ ; arr[r+1]--;} 
            }
        }
        
        return false ; 
    }
};
