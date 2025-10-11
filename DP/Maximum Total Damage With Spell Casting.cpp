#define ll long long
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // HERE I HAVE PUT THE ARRAY WITH THEIR FREQUENCY IN A SORTED WAY BECAUSE IT IS EASY TO FIND
        // WHY I HAVE TAKEN FREQUENCY BECAUSE IN THE QUESTION IT IS GIVEN WE CANT TAKE power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
        // SUPPOSE POWER IS [1,1,3,4] SO HERE SUPPOSE POWER[I] IS 1 SO WE CANT TAKE 
        // 1-2=-1,1-1=0,1+1=2,1+2=3 BUT WE CAN TAKE 1 WHICH IS POWER[I] SO TO OPTIMISE FURTHER
        // WE CAN TAKE THE FREQUENCY OF THE HOW MANY TIME EACH NUMBER OCCURS THEREFORE IF WE WILL TAKE THAT NUMBER
        //  Multiple spells can have the same damage value.
        // WE WILL TAKE ALL THE OCCURENCES OF THAT NUMBER SO THAT WE CAN GET MAXIMUM TOTAL DAMAGE

        map<int,int>mpp;
        for(auto i:power) mpp[i]++;
        vector<pair<ll,ll>>v;
        for(auto [u,f]:mpp) v.push_back({u,f});
        int n=v.size();

        // NOW DP STARTS IT IS TABULATION DP AS MEMOISATION + RECURSION  I HAVE TRIED BUT GIVES TLE
        // SO HERE MORE OPTIMISED TABULATION APP
        // IT IS TAKE OR NOT TAKE DP
        // WHAT WILL BE BASE CASE -> IF THERE IS ONLY ONE ELEMENT SO WE CAN TAKE THAT ELEMENT BECAUSE WE WANT MAXIMUM
        // SO THIS MAKES NO SENSE TO NOT TAKE THAT ELEMENT
        vector<ll>dp(n,0);
        dp[0]=v[0].first*v[0].second;
        // NOW WE WILL ITERATE FROM I =1 TO I<N AND FOR EACH I WE WILL VHECK IF THE DIFFERENCE OF TWO POWER SHOULD NOT BE LESS THAN 2 BECAUSE
        // AS STATED IN THE QUESTION
        // SO WE WILL RUN A OTHER J LOOP FROM I-1 TO 0 WHICH WILL GIVE ME THE INDEX OF J WHOSE DIFFERENCE IS JUST GREATER THAN 2
        // AND SUPPOSE IF WE RUN INTO EDGE CASE
        // EDGE CASE-> SUPPOSE POWER IS [7,1,6,3] SO V WILL BE V=[{1->1,3->1,6->1,7->1}]
        // DP[0]=1*1=1;
        // NOW FOR LOOP STARTS FROM 1
        // DP[1]=MAX(TAKE,NOTTAKE);
        // NOTTAKE WILL BE SIMPLE JUST DP[I-1];
        // FOR TAKE WE WILL CHECK IF THE CONDITION GIVEN IN QUESTION SATTISFY OR NOT
        // HERE I IS 1 AND WILL START FROM I-1=0 SO WE WILL CHECK IF 3-1>2 IT IS NOT SO WE WILL J-- HERE J BECOMES NEGATIVE SO 
        // WE WILL JUST TAKE DP[J] TO 0 BECAUSE HERE WE CANT TAKE 3 AS ITS DIFFERENCE WITH ALL ITS PREV ELEMENTS IS <=2
        // SO HERE TAKE=0+V[I].FIRST+V[I].SECOND AS THERE CAN BE MULTIPLE OCCURENCES
        // AND NOTTAKE=DP[I-1]
        // SO DP[1]=MAX(0+3*1,DP[0])=MAX(3,1)=3;
        // AND SIMILARLY FOR THE REST OF THE CODE WE CANT DO THIS
        for(int i=1; i<n; i++){
            int j=i-1;
            while(j>=0 && v[i].first-v[j].first<=2){
                j--;
            }
            //HERE NO PREV ELEMENT CAN BE TAKEN
            if(j<0) dp[i]=max(dp[i-1],0+v[i].first*v[i].second);
            // HERE WE GOT THE PREV ELEEMNT SO WE CAN JUST ADD THAT TO MAXIMISE OUR ANS
            else dp[i]=max(dp[i-1],dp[j]+v[i].first*v[i].second);
        }
        return dp[n-1];
    }
};
