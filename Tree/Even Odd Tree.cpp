//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            int N=q.size();
            int prev_val;
            if(level%2==0){
                prev_val=INT_MIN;
            }
            else{
                prev_val=INT_MAX;
            }

            while(N--){
                TreeNode* u=q.front();
                q.pop();

                if(level%2==0){
                    if(u->val%2==0 || u->val<=prev_val) return false;
                }
                else{
                    if(u->val%2!=0 || u->val>=prev_val) return false;
                }

                prev_val=u->val;

                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            level++;
        }
        return true;
    }
};
