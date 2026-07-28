class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26);
        for(int x:s){
            v[x-'a']++;
        }

        string left ="";
        char mid=' ';
        for(int i=0;i<26;i++){
            if(v[i] % 2 == 1){
                mid = i + 'a';
            }
            int num=v[i]/2;
            while(num--){
                left.push_back(char(i + 'a'));
            }

            
        }
        string right=left;
            reverse(right.begin(),right.end());
            if(mid != ' ') return left+string(1,mid)+right;
            return left+right;
    }
};
