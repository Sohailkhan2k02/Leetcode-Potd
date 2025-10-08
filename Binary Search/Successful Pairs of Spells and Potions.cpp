class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        for(int i = 0;i<n;i++){
            int low = 0, high = m - 1, mid;
            long long spell = spells[i], potion;
            while(low <= high){
                mid = (low + high)/2;
                potion = spell * potions[mid];
                if(potion >= success)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            spells[i] = m - low;
        }
        return spells;
    }
};
