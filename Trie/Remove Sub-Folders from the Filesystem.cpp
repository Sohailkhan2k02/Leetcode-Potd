//APPROACH -1
//T.C : O(nlogn×average(∣folder∣))
//S.C : O(1)
class Solution {
public:
    static vector<string> removeSubfolders(vector<string>& folder) {
        const int n=folder.size();
        sort(folder.begin(), folder.end());
        vector<string> ans={folder[0]};
    //    ans.reserve(40000);
        string prev=folder[0];
        for(int i=1; i<n; i++){
            string s=folder[i];
            if (s.find(prev+'/')!=0){
                ans.push_back(s);
                prev=s;
            }
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

//APPROACH -2
//T.C : Trie: O(n×average(∣folder∣))
//S.C : O(n×average(∣folder∣))
struct Trie {
    array<unique_ptr<Trie>, 27> links; // 26 letters + 1 for '/'
    bool isEnd = 0;

    // Insert folder into trie returning pos for last '/'
    int insert(string_view path) {
        Trie* node = this;
        int sz = path.size(), pos = 0;
        for (int i = 0; i < sz; i++) {
            char c=path[i];
            int idx=(c=='/') ? 26 : c-'a'; // Use 26 for '/'
            if (idx == 26)
                pos = i;
            if (!node->links[idx]) 
                node->links[idx] = make_unique<Trie>();
            node=node->links[idx].get();
        }
        node->isEnd = 1;
        return pos;
    }

    // Check if this folder is a subfolder of an already inserted folder
    bool isSubfolder(const string& path, int pos) {
        if (pos==0) return 0; // Each folder name is unique.
        Trie* node = this;
        for (int i = 0; i < pos; i++) {
            char c = path[i];
            int idx=(c=='/')?26:c - 'a';
            node = node->links[idx].get();
            // it is a subfolder
            if (path[i+1] == '/' && node->isEnd)
                return 1;
        }
        return 0;
    }
};

class Solution {
public:
    Trie trie;
    vector<string> removeSubfolders(vector<string>& folder) {
        // First pass: Insert all folder paths into the trie
        int n=folder.size(), i=0;
        vector<int> pos(n);
        for (string_view path : folder)
            pos[i++]=trie.insert(path);

        vector<string> ans;

        // Second pass: Check each folder to see if it's a subfolder
        for (int i=0; i<n; i++) {
            string path=folder[i];
            if (!trie.isSubfolder(path, pos[i]))
                ans.push_back(path);
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
