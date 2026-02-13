class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;
        
        // for only a or only b or only c 
        int count = 1;
        for(int i=1;i<n;i++){
            if(s[i] != s[i-1]) count = 0;
            count++;
            ans = max(ans,count);
        }


        int a = 0,b = 0,c = 0;
        map<pair<int,int>,int> abc;
        map<pair<int,int>,int> ab;
        map<pair<int,int>,int> bc;
        map<pair<int,int>,int> ac;

        abc[{0,0}] = 0;
        ab[{0,0}] = 0;
        bc[{0,0}] = 0;
        ac[{0,0}] = 0;

        for(int i=0;i<n;i++){
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;
            
            if(abc.find({a-b,b-c}) != abc.end()) ans = max(ans,(i+1)-abc[{a-b,b-c}]);
            else abc[{a-b,b-c}] = i+1;
            if(bc.find({b-c,a}) != bc.end()) ans = max(ans,(i+1)-bc[{b-c,a}]);
            else bc[{b-c,a}] = i+1;
            if(ac.find({a-c,b}) != ac.end()) ans = max(ans,(i+1)-ac[{a-c,b}]);
            else ac[{a-c,b}] = i+1;
            if(ab.find({a-b,c}) != ab.end()) ans = max(ans,(i+1)-ab[{a-b,c}]);
            else ab[{a-b,c}] = i+1;
        }

        return ans;              
    }
};
