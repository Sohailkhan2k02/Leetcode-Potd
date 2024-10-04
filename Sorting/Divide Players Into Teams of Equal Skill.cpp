//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        /* hello 3 2 5 1 3 4
        now -> 1 2 3 3 4 5
        
        1 4 3 2 2 3 
        1 2 2 3 3 4

        1 7 2 6 3 5 4 4 5 3

        1 2 3 3 4 4 5 5 6 7 

        */
        int n = skill.size();
        if(skill.size() % 2 != 0) return -1;
        sort(skill.begin(), skill.end());
        long long ans = 0;

        int val = skill[0] + skill[n - 1];
        ans += skill[0] * skill[n - 1];;
        int i = 1;
        int j = n - 2;
        while(i < j){
            int f = skill[i];
            int s = skill[j];

            int curr = f + s;
            if(curr != val) return -1;

            ans += (f * s);
            i++;
            j--;
        }

        return ans;


    }
};
