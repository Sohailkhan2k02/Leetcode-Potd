//T.C : O(n)
//S.C : O(max(width))
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int N=q.size();
            vector<TreeNode*>vc;
            while(N--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

                if(level%2!=0){
                    vc.push_back(temp);
                }
            }
            if(level%2!=0){
                int i=0,j=vc.size()-1;
                while(i<j){
                    swap(vc[i]->val,vc[j]->val);
                    i++,j--;
                }
            }
            level++;
        }
        return root;
    }
};
