//Approach-1 - TLE - Just applying concept of Leetcode-931 (Minimum Falling Path Sum)
//T.C : O(m*n*n)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    ll maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<ll> prev(n);
        int score = 0;
        
        for(int col = 0; col < n; col++) {
            prev[col] = points[0][col];
        }
        
        for(int i = 1; i<m; i++) {
            vector<ll> curr(n);
            for(int j = 0; j<n; j++) {
                for(int k = 0; k < n; k++) {
                    curr[j] = max(curr[j], prev[k] + points[i][j] - abs(k-j));
                }
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};


//Approach-2 (Accepted)
/*
	This is similar to Approach-1 but we are finding the best prev column smartly.
	Read comments below to understand.
*/
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    ll maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<ll> prev(n);
        int score = 0;
        
        for(int col = 0; col < n; col++) {
            prev[col] = points[0][col];
        }
        
        for(int i = 1; i<m; i++) {
            vector<ll> curr(n);
            auto left = curr, right = curr;
            
            /*
                While calculating left and right, we will find what will be added to
                points[i][j] (either left[j] or right[j]) which yields maximum value.
                Is it the prev row top value = prev[j];
                or is it prev row left value(but then subtract -1 due to one gap) = prev[j-1]-1
                or is it prev row left left value = prev[j-2]-2
                ans so on.
                Instead of comparing with all previous left (prev[j], prev[j-1]-1, prev[j-2]-2 etc)
                We know that left stores the bext left values.
                So we just subtract -1 from left[j-1] to get the result.
                
                i.e. (In short)
                essentially left[2] = max(pre[2], lft[1]-1) is the max for index 2 
                (instead of calculating from iterating from index 0) is because that
                lft[1]-1 already calculated for index 1 which includes the comparison
                between left[0]-1 and prev[1], so left[1] -1 includes left[0] -2, and prev[1] - 1 already
                
				similar story goes for right.
            */
            
            //Fill left
            left[0] = prev[0];
            for(int j = 1; j<n; j++) {
                left[j] = max(prev[j], left[j-1]-1); // points[i][j] will be added later            
            }
            
            //Fill right
            right[n-1] = prev[n-1];
            for(int j = n-2; j >= 0; j--) {
                right[j] = max(prev[j], right[j+1]-1); // points[i][j] will be added later
            }
            
            for(int j = 0; j<n; j++)
                curr[j] = points[i][j] + max(left[j], right[j]); // points[i][j] added here
            
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};
