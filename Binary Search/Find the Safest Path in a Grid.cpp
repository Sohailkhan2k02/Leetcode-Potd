//T.C : O(log(n) * n^2)
//S.C : O(n^2)
class Solution {
public: 
    // YOU JUST HAVE TO USE MULTIPLE CONCEPTS IN THIS IT IS A GOOD QUESTION
    // SEE I WILL GO THROUGH MY TOTAL UNDERSTANDING HOW I APPROACH THIS PROBLEM
    // FIRST I THOUGHT IT WAS A SIMPLE PROBLEM I THOUGHT SIMPLE BFS WILL WORK BUT
    // I HAVEN'T READ THE FULL QUESTION BUT HERE WE HAVE TO DO FEW THINGS FIRST WE HAVE TO FIND A PATH
    // WHERE THE SAFENESS FACTOR IS MAXIMUM AND SAFENESS FACTOR CAN BE DEFINED BY THE MINIMUM OF 
    // MANHATTAN DISTANCE FROM THE THIEF FOR EG IF WE ARE AT 0,0 AND THIEF IS AT 0,3 AND 3,0
    // SOTHE DISTANCE OF (0,0) FROM (0,3) IS 3 AND FROM (0,0) FROM (3,0) IS ALSO 3 AND WE HAVE TO 
    // TAKE THE MINIMUM OF BOTH ...
    // NOW SAFENESS FACTOR CAN BE MINIMUM OF 0 AS WE KNOW THAT THE MINIMUM DISTANCE FROM THE NODE TO THE THIEF CAN BE 1
    // AND MAX CAN BE INFINITY SO WE CAN DO THIS AS SF(SAFENESS FACTOR) CAN BE 1,2,3.... AND SO ON
    // HERE WE CAN SEE THAT FOR SAFENESS FACTOR WE CAN USE BINARY SEARCH AS IT WILL GIVE US A SF IN A EFFICIENT WAY
    // AND TO FIND THE MIN DISTANCE OF EVERY GRID WE CAN USE BFS FROM 0,0 AND CALCULATE AND THEN 
    // AGAIN CALL BFS FOR (0,1) AND SO ON BUT IT WILL GIVE TLE AS IT IS BRUTE FORCE
    //SO WHY NOT WE START THE BFS FROM THE THIEFS SUPPOSE IF THERE ARE 2 THIEVES WE CAN START
    // THE BFS FROM THE THEIVES AND CALL IT AT THE SAME TIME IT IS ALSO CALLED MULTISOURCE BFS
    // NOW I WILL DO A DRY RUN HERE WHICH WILL MAKE U UNDERSTAND
    //   SUPPOSE grid = [[0,0,1],[0,0,0],[0,0,0]]
    // NOW [0,0,1]
    //    [0,0,0]
    //    [1,0,0]
    /* 
     IF WE WANT TO START A FIRST WE HAVE TO FIND A MIN DISTANCE OF EACH GRID HOW WE CAN DO THAT
     WE CAN DO THAT BY VISITING THIEFES GRID AND CALLING BFS AT A SAME TIME
     IN QUEUE WE WILL PUT [[0,2],[2,0]] IN LEVEL 0
     NOW IN 0,2 WE CAN GO 4 DIR UP,DOWN,LEFT,RIGHT
     WE GO 0,1 SO MANHATTAN DISTANCE WILL BE 1 WE GO 1,2 MANHATTAN DISTANCE WILL BE 1
     AND IN 2,0 WE GO 1,0 DISTANCE WILL BE 1 AND WE GO 2,1 MANHATTAN DISTANCE WILL BE 1
     WE WILL PUT ALL THIS IN A QUEUE AT SAME LEVEL 1 
     [[0,1][1,2][2,1],[1,0]] LEVEL 1
     NOW TAKE 0,1 WE GO 0,0  MANHATTAN DISTANCE WILL BE 2 WE GO 1,1  MANHATTAN DISTANCE WILL BE 2
     NOW TAKE 1,2 WE GO 2,2  MANHATTAN DISTANCE WILL BE 2 
     NOW TAKE 2,1 ALL GRIDS ARE ALREADY VIS
     NOW TAKE 1,0 ALREADY VIS 
     [[0,0],[1,1],[2,2]] LEVEL 2
     HERE EVERY GRIDS ARE VIS AND WE GO OUT MIN DISTANCE GRID :-
     [2,1,0]
     [1,2,1]
     [0,1,2]
     TAKE THE THEIVES DISTANCE 0
     AND THEN WE WILL CALCULATE SF USING BINARY SEARCH IN THIS MIN DISTANCE GRID

    */
    
    bool check(vector<vector<int>>&mini, int sf){
        int n=mini.size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]=1;

        if(mini[0][0]<sf){
            return false;
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i==n-1 && j==n-1){
                return true;
            }

            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int k=0; k<4; k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]!=1){
                    if(mini[nrow][ncol]<sf){
                        continue;
                    }
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return false;
    }
    // void print(vector<vector<int>> &vec) {
    //     for (int i=0; i<vec.size(); i++) {
    //         for (int j=0; j<vec[0].size(); j++) {
    //             cout << vec[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1){
            return 0;
        }
        vector<vector<int>>mini(n,vector<int>(n,0));
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int level=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                mini[u][v]=level;

                int delrow[]={-1,0,1,0};
                int delcol[]={0,1,0,-1};
                for(int k=0; k<4; k++){
                    int nrow=u+delrow[k];
                    int ncol=v+delcol[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]!=1){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
            level++;
        }

        // print(mini);
        
        //BINARY SEARCH 
        int l=0,r=400;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mini,mid)){
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};
