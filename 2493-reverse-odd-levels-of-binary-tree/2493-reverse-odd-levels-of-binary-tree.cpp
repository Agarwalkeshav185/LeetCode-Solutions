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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> stk;
        stk.push(root);
        int levi=0;
        while(!stk.empty()){
            int size = stk.size();
            vector<TreeNode*> lev;
            for(int i=0; i<size; i++){
                TreeNode* temp = stk.front();
                lev.push_back(temp);
                stk.pop();
                if(temp->left) stk.push(temp->left);
                if(temp->right) stk.push(temp->right);
            }
            if(levi%2){
                for(int k=0; k< lev.size()/2; k++){
                    swap(lev[k]->val, lev[lev.size()-1-k]->val);
                }
            }
            levi++;
        } 
        return root;
    }
};