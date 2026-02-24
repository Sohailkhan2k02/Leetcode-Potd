class Solution {
public:
    int val = 0;

    void method(TreeNode* root, string &sum) {
        if (!root) return;

        sum.push_back(root->val + '0');

        if (!root->left && !root->right) {
            val += stoi(sum, nullptr, 2); // base 2
        } else {
            method(root->left, sum);
            method(root->right, sum);
        }

        sum.pop_back(); // backtrack
    }

    int sumRootToLeaf(TreeNode* root) {
        string sum = "";
        method(root, sum);
        return val;
    }
};
