//TWO PASS APPROACH
// T.C : O(n)
// S.C : O(h)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>levelSum;
        while(!q.empty()){
            int sum=0;
            int N=q.size();
            while(N--){
                TreeNode* node=q.front(); q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelSum.push_back(sum);
        }

        q.push(root);
        int l=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int sum=0;
                TreeNode* node=q.front(); q.pop();
                if(node->left){
                    sum+=node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    sum+=node->right->val;
                    q.push(node->right);
                }
                if(node->left){
                    node->left->val=levelSum[l+1]-sum;
                }
                if(node->right){
                    node->right->val=levelSum[l+1]-sum;
                }
            }
            l++;
        }
        root->val=0;
        return root;
    }
};
