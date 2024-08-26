//T.C : O(n)
//S.C : O(h) height of tree
class Solution {
public:
vector<int> ans;
    void traverse(Node* root) {
        if(root==nullptr){
            return;
        }
        for(auto c: root->children){
            traverse(c);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        traverse(root);
        return ans;
    }
};
