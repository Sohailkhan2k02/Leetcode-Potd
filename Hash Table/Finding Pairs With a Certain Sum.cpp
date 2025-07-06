class FindSumPairs {

    vector<int> a;
    vector<int> b;
    unordered_map<int,int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;

        for(int i = 0; i < b.size(); i++) {
            mp[b[i]]++;
        }
    }
    
    void add(int index, int val) {
        
        int num = b[index];
        mp[num]--;

        if(mp[num] == 0) {
            mp.erase(num);
        }

        b[index] += val;
        mp[b[index]]++;
        
    }
    
    int count(int tot) {

        int cnt = 0;

        for(int i = 0; i < a.size(); i++) {

            if(mp.count(tot - a[i]) > 0) {
                cnt += mp[tot - a[i]];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
