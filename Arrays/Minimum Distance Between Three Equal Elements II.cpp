class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size() < 3){
            return -1;
        }
        
        unordered_map<int,int> mp1;
        for(int i = 0; i < nums.size(); i++){
            mp1[nums[i]]++;
        }

        multimap<int,pair<int,int>> mp;
        for(int i = 0; i < nums.size(); i++){
            mp.insert({nums[i], {mp1[nums[i]], i}});
        }

        int min_dist = INT_MAX;

        int p1 = -1, p2 = -1;
        int pnum = -1;

        for(auto x : mp){
            int num = x.first;
            int freq = x.second.first;
            int idx = x.second.second;
            if(freq >= 3){
                if(num != pnum){
                    p1 = -1;
                    p2 = -1;
                }
                if(p1 == -1){
                    p1 = idx;
                }
                else{
                    if(p2 == -1){
                        p2 = idx;
                    }
                    else{
                        int i = p1;
                        int j = p2;
                        int k = idx;
                        int dist = abs(i - j) + abs(j - k) + abs(k - i);
                        if(dist < min_dist){
                            min_dist = dist;
                        }
                        p1 = p2;
                        p2 = idx;
                    }
                }
                pnum = num;
            }
        }
        if(min_dist == INT_MAX){
            return -1;
        }
        else{
            return min_dist;
        }
    }
};
