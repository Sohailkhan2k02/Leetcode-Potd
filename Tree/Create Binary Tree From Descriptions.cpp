//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>child;
        for(auto vec:d){
            int u=vec[0],v=vec[1],l=vec[2];
            if(mpp.find(u)==mpp.end()){
                mpp[u]=new TreeNode(u);
            }
            if(mpp.find(v)==mpp.end()){
                mpp[v]=new TreeNode(v);
            }
            if(l==1){
                mpp[u]->left=mpp[v];
            }
            else{
                mpp[u]->right=mpp[v];
            }
            child.insert(v);
        }

        TreeNode* root=NULL;
        for(auto i:mpp){
            int u=i.first;
            TreeNode *v=i.second;
            if(child.find(u)==child.end()){
                root=v;
                break;
            }
        }
        return root;
    }
};
