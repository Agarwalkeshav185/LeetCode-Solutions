/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, int val, int depth, int curdepth){
        if(root== NULL) return;

        inorder(root->left, val, depth, curdepth+1);
        if(curdepth == depth-1){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = newLeft;
            root->left->left = left;
            root->right = newRight;
            root->right->right = right;
        }
        inorder(root->right, val, depth, curdepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        inorder(root, val, depth, 1);
        return root;

    }
};