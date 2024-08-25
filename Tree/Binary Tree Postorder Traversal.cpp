//T.C : O(n)
//S.C : O(h) height of the tree
class Solution {
public:
    void f(TreeNode* root,vector<int>&res){
        if(!root) return;
        f(root->left,res);
        f(root->right,res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        f(root,res);
        return res;
    }
};
