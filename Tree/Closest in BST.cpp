/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, int k, int& ans) {

            if (!root) {
                return;
            }

            ans = min(ans, abs(k - root->data));
            if (k <= root->data) {
                solve(root->left, k, ans);
            }
            else {
                solve(root->right, k, ans);
            }

            return;
        }
        int minDiff(Node *root, int k) {
            // code here

            int ans = INT_MAX;
            solve(root, k, ans);
            return ans;

            while (root) {

                ans = min(ans, abs(k - root->data));
                if (k <= root->data) {
                    root = root ->left;
                } else {
                    root = root->right;
                }
            }

            return ans;
        }
};
