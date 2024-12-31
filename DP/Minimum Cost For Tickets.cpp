//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int arr[396][366];
    int solve(vector<int>& days, vector<int>& costs, int valid, int i){
        if(i == days.size()) return 0;

        if(arr[valid][i] != -1) return arr[valid][i];
        if(valid >= days[i]){
            // Ticket pass already hai
            return arr[valid][i] = solve(days, costs, valid, i+1);
        }
        
        // Ticket kharidna hoga
        int a = costs[0] + solve(days, costs, days[i], i+1);
        int b = costs[1] + solve(days, costs, days[i]+6, i+1);
        int c = costs[2] + solve(days, costs, days[i]+29, i+1);

        return arr[valid][i] = min(min(a,b),c);
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(arr, -1, sizeof(arr));
        return solve(days, costs, 0, 0);
    }
};
