class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        if(asteroids[0] > mass)
            return false;

        long long pmass = mass + asteroids[0];
        for(int i=1; i<asteroids.size(); i++) {
            if(pmass < asteroids[i]) 
                return false;
            
            pmass += asteroids[i];
        }

        return true;
    }
};
