class Solution {
public:
    void bs(int s , int sh , int e , int eh , int &ans ) {
        int st = s + 1 , end = e - 1 ;
        while ( st <= end ) {
            int mid = st + ( end - st ) / 2 ; 
            int attainableHeight = sh + ( mid - s ) ; 
            int restrictableHeight = eh + ( e - mid ) ; 
            if ( attainableHeight <= restrictableHeight ) {
                ans = max ( ans , attainableHeight ) ; 
                st = mid + 1 ;  
            } else {
                end = mid - 1 ;  
            }
        }
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int res = restrictions.size() ; 
        sort(restrictions.begin(),restrictions.end()) ; 
        for ( int i = 0 ; i < res ; i ++ ) {
            restrictions[i][1] = min ( restrictions[i][0] -1 , restrictions[i][1]) ; 
            if ( i ) {
                int dis = restrictions[i][0] - restrictions[i-1][0] ;
                int lim = restrictions[i-1][1] + dis ; 
                restrictions[i][1] = min ( restrictions[i][1] , lim ) ; 
            }
        }
        for ( int i = res - 1 ; i >= 0 ; i -- ) {
            if ( i != res - 1 ) {
                int dis = restrictions[i+1][0] - restrictions[i][0] ;
                int lim = restrictions[i+1][1] + dis ; 
                restrictions[i][1] = min ( restrictions[i][1] , lim ) ; 
            }
        }
        int start = 0 , height = 0 , ans = 0 ; 
        for ( int i = 0 ; i < res ; i ++ ) {
            int end = restrictions[i][0] - 1 ; 
            int heightRes = restrictions[i][1] ;
            int dis = end - start ;
            int maxHeightAttainable = height + dis ;
            if ( maxHeightAttainable <= heightRes ) {
                ans = max ( maxHeightAttainable , ans ) ; 
                start = end ; 
                height = maxHeightAttainable ; 
            } else {
                bs(start,height,end,heightRes,ans) ; 
                start = end ; 
                height = heightRes ; 
            }
        }

        int dis = n - 1 - start ; 
        ans = max ( height + dis , ans ) ; 
        return ans ; 
    }
};
