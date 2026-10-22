class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = (int)nums.size();
        int id = 0;
        for(int x: nums){
            if(x==0){
                break;
            }
            ++id;
        }
        int ogid = id;
        int cnt = 1;
        int pr = nums[id];
        bool ok1 = true;
        bool ok2 = true;
        while(cnt < n){
            id = (id + 1)%n;
            if(nums[id] != pr + 1) {ok1 = false; break; }
            pr = nums[id];
            ++cnt;
        }
        id = ogid;
        cnt = 1;
        pr = nums[id];
        while(cnt < n){
            id = (id - 1 + n)%n;
            if(nums[id] != pr + 1) {ok2 = false; break; }
            pr = nums[id];
            ++cnt;
        }
        if(!ok1 && !ok2) return -1;
        if(ok1) return min(ogid, n - ogid + 2);
        else return min(n - ogid, ogid + 2);
        
    }
};
