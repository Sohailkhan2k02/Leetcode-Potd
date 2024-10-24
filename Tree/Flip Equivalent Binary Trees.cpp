//ITERATIVE APPROACH
//T.C : O(n+n)
//S.C : O(n+n)
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL && root2!=NULL || root2==NULL && root1!=NULL) return false;
        if(root1->val!=root2->val) return false;
        queue<TreeNode*>q1,q2;
        q1.push(root1),q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            string r1="",r2="";
            auto node1=q1.front(); q1.pop();
            auto node2=q2.front(); q2.pop();
            if(node1->val!=node2->val) return false;
            if(node1->left) {
                r1+=to_string(node1->left->val);
            }
            if(node1->right){
                r1+=to_string(node1->right->val);
            }
            if(node2->left){
                r2+=to_string(node2->left->val);
            }
            if(node2->right) {
                r2+=to_string(node2->right->val);
            }
            sort(r1.begin(),r1.end()),sort(r2.begin(),r2.end());
            cout<<r1<<" "<<r2<<" ";
            if(r1!=r2) return false;
            if(node1->left && node2->left && node1->left->val==node2->left->val){
                q1.push(node1->left);
                q2.push(node2->left);
            }
            else if(node1->left && node2->right && node1->left->val==node2->right->val){
                q1.push(node1->left);
                q2.push(node2->right);
            }
            else if(node1->left) return false;

            if(node1->right && node2->right && node1->right->val==node2->right->val){
                q1.push(node1->right);
                q2.push(node2->right);
            }
            else if(node1->right && node2->left && node1->right->val==node2->left->val){
                q1.push(node1->right);
                q2.push(node2->left);
            }
            else if(node1->right) return false;
        }
        return true;
    }
};

//SECOND APPROACH
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr and root2 == nullptr) return true;
        if(root1 == nullptr or root2 == nullptr) return false;
        if(root1->val != root2->val) return false;
        return ((flipEquiv(root1->left, root2->left) or flipEquiv(root1->left, root2->right)) and (flipEquiv(root1->right, root2->left) or flipEquiv(root1->right, root2->right)));
    }
};
