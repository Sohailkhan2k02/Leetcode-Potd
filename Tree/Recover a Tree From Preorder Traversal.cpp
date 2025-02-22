//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        // Step 1: Extract depth-value pairs
        vector<pair<int, int>> vp;
        int i = 0;
        while (i < s.size()) {
            int depth = 0;
            while (i < s.size() && s[i] == '-') {
                depth++;
                i++;
            }
            int num = 0;
            while (i < s.size() && s[i] != '-') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            vp.push_back({depth, num});
        }

        // Step 2: Construct tree using a stack
        stack<pair<int, TreeNode*>> st;
        TreeNode* root = nullptr;
        
        for (auto it : vp) {
            int depth = it.first;
            int nodeVal = it.second;
            TreeNode* node = new TreeNode(nodeVal);

            while (!st.empty() && st.top().first >= depth) {
                st.pop();
            }

            if (!st.empty()) {
                TreeNode* parent = st.top().second;
                if (parent->left == nullptr) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            } else {
                root = node; // Assign root for first node
            }

            st.push({depth, node});
        }
        
        return root;
    }
};
