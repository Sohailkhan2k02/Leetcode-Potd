//T.C : O(n)
//S.C : O(n)
class Solution {
public:
TreeNode * BuildTree(vector<int>& preorder  , int  preStart , int  preEnd , vector<int> &postorder , int   postStart , int   postEnd , unordered_map<int , int>  & postMap )
{

    if(preStart>preEnd  || postStart >postEnd)
    {
        return  NULL;
    }
    TreeNode * root= new TreeNode(preorder[preStart]);
    if(preStart !=preEnd)
    {
        int leftVal=preorder[preStart+1];
        int rootIndex= postMap[leftVal];
        int leftSize=rootIndex-postStart+1;
        root->left=BuildTree(preorder , preStart+1 , preStart+leftSize  , postorder , postStart , rootIndex , postMap);
        root->right=BuildTree(preorder , preStart+leftSize+1 , preEnd , postorder , rootIndex+1  , postEnd-1  , postMap);

    }
    return root;

}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int  preStart=0;
        int postStart=0;
        int preEnd=preorder.size()-1;
        int postEnd=postorder.size()-1;
        unordered_map<int , int> postMap;
        for(int i=0;i<preorder.size();i++)
        {
            postMap[postorder[i]]=i;
        }
          TreeNode *root = BuildTree(preorder , preStart , preEnd , postorder , postStart , postEnd , postMap);
          return root;
        
    }
};
