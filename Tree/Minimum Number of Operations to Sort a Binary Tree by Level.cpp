//T.C : O(max_width+temp.size()log(temp.size())+temp.size())
//S.C : O(max_width)
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int N=q.size();
            vector<pair<int,int>>temp;
            int i=0;
            while(N--){
                TreeNode* curr=q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                temp.push_back({curr->val,i++});
            }
            sort(temp.begin(),temp.end());
            vector<bool>vis(temp.size(),0);
            for(int i=0; i<temp.size(); i++){
                if(vis[i] || temp[i].second==i) continue;
                int sz=0,j=i;
                while(!vis[j]){
                    vis[j]=1;
                    j=temp[j].second;
                    sz++;
                }
                if(sz>1) cnt+=sz-1;
            }
            level++;
        }
        return cnt;
    }
};
