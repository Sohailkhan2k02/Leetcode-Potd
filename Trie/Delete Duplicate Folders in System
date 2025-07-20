struct Trie {
    unordered_map<string, Trie*> children;
    string subFolderStr;
    bool isDeleted = false;
};

class Solution {
public:
    Trie* root;
    unordered_map<string, int> subPathCount;

    void AddToTrie(vector<string>& path) {
        Trie* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new Trie();
            }
            node = node->children[folder];
        }
    }

    string dfsSerialize(Trie* node) {
        if (node->children.empty()) {
            node->subFolderStr = "";
            return "";
        }

        vector<pair<string, string>> childReps;

        for (auto& [name, child] : node->children) {
            string rep = dfsSerialize(child);
            childReps.emplace_back(name, rep);
        }

        sort(childReps.begin(), childReps.end());

        string key;
        for (auto& [name, rep] : childReps) {
            key += "(" + name + rep + ")";
        }

        node->subFolderStr = key;
        subPathCount[key]++;
        return key;
    }

    void dfsMarkDuplicates(Trie* node) {
        if (node->subFolderStr != "" && subPathCount[node->subFolderStr] > 1) {
            node->isDeleted = true;
            return;
        }

        for (auto& [name, child] : node->children) {
            dfsMarkDuplicates(child);
        }
    }

    void dfsCollect(Trie* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (child->isDeleted) continue;
            path.push_back(name);
            result.push_back(path);
            dfsCollect(child, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        root = new Trie();

        // 1. Build Trie
        for (auto& path : paths) {
            AddToTrie(path);
        }

        dfsSerialize(root);

        dfsMarkDuplicates(root);

        vector<vector<string>> result;
        vector<string> tempPath;
        dfsCollect(root, tempPath, result);

        return result;
    }
};
