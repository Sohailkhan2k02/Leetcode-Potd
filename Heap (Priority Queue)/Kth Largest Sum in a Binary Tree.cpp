//T.C : O(n*logk)
//S.C : O(logk)
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        using ll=long long;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        queue<TreeNode*>q;
        q.push(root);
        ll l=0;
        pq.push(root->val);
        while(!q.empty()){
            int N=q.size();
            ll sum=0;
            while(N--){
                auto node=q.front(); q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(sum);
            if(pq.size()>k){
                pq.pop();
            }
            l++;
        }
        if(l<k) return -1;
        return pq.top();
    }
};
