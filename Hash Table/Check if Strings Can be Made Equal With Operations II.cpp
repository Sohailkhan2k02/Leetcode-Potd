class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<int,int> even, odd;

        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                even[s1[i]]++;
                even[s2[i]]--;
            }else{
                odd[s1[i]]++;
                odd[s2[i]]--;
            }
        }

        for(auto it:even){
            if(it.second!=0)return false;
        }

        for(auto it:odd){
            if(it.second!=0)return false;
        }

        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
