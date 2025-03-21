//T.C: O(n*n)
//S.C : O(n)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;

        unordered_set<string> have;

        for (string ing : supplies) {
            have.insert(ing);
        }

        vector<int> ingGotten(ingredients.size());
        bool add = false;

        while (true) {
            add = false;
            for (int i = 0; i < ingredients.size(); i++) {
                if (recipes[i] == "0") {
                    continue;
                }
                for (int j = 0; j < ingredients[i].size(); j++) {
                    if (ingredients[i][j] == "0") {
                        continue;
                    }
                    if (have.count(ingredients[i][j])) {
                        ingredients[i][j] = "0";
                        ingGotten[i]++;
                        add = true;
                    }
                    if (ingGotten[i] == ingredients[i].size()) {
                        ans.push_back(recipes[i]);
                        have.insert(recipes[i]);
                        recipes[i] = "0";
                    }
                }
            }
            if (!add) {
                return ans;
            }
        }
    }
};
