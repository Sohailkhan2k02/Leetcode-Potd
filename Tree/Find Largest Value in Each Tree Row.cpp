//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int N=q.size();
            int maxi=INT_MIN;
            while(N--){
                TreeNode* curr=q.front(); q.pop();
                maxi=max(maxi,curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};
