//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    void f(TreeNode* root, vector<int>& t) {
        if(root == NULL) return;
        f(root->left, t);
        t.push_back(root->val);
        f(root->right, t);
    }
    int f(int val,vector<int>&t){
        int sum=0;
        for(int i=0; i<t.size(); i++){
            if(t[i]>=val){
                sum+=t[i];
            }
        }
        return sum;
    }

    void f1(TreeNode* root, vector<int>&t){
        if(root==NULL) return;
        f1(root->left,t);
        root->val=f(root->val,t);
        f1(root->right,t);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>t;
        f(root,t);
        f1(root,t);
        return root;
    }
};


//Simple recursive approach
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    void solve(TreeNode* root, int &sum) {
        if(!root) { //root == NULL
            return;
        }
        solve(root->right, sum); //RIGHT is covered
        sum += root->val;
        root->val = sum;
        solve(root->left, sum); //Covergin the left
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};
