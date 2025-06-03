#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        set<int> avbox;
        for(int box : initialBoxes) {
           if(status[box] == 1) {
                q.push(box);
            }
            else{
                avbox.insert(box);
            }
        }
        set<int> keysSet;
        int ans = 0;
        while(!q.empty()){
            int box =q.front();
            q.pop();
            ans+= candies[box];
            for(auto x: containedBoxes[box]) {
                if(status[x] == 1) {
                    q.push(x);
                }
                else{
                    if(keysSet.find(x) != keysSet.end()) {
                        q.push(x);
                        keysSet.erase(x);
                    }
                    else{
                        avbox.insert(x);
                    }
                }

            }
            for(auto x: keys[box]) {
                if(avbox.find(x) != avbox.end()) {
                    avbox.erase(x);
                        q.push(x);

                }
                else{
                    keysSet.insert(x);
                }
            }

        }
        return ans; 
    }
};
