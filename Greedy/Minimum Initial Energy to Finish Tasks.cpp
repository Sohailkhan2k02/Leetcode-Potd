#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int initialEnergy = 0;
        int currentEnergy = 0;

        for (auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (currentEnergy < minimum) {
                int need = minimum - currentEnergy;
                initialEnergy += need;
                currentEnergy += need;
            }

            currentEnergy -= actual;
        }

        return initialEnergy;
    }
};
