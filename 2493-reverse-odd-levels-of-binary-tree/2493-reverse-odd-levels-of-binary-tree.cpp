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
        vector<vector<int>> levels;
        queue<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            int size = stk.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* temp = stk.front();
                level.push_back(temp->val);
                stk.pop();
                if(temp->left) stk.push(temp->left);
                if(temp->right) stk.push(temp->right);
            }
            levels.push_back(level);
        } 
        for(int i=0;i<levels.size(); i++){
            if(i%2){
                reverse(levels[i].begin(), levels[i].end());
            }
        }
        stk.push(root);
        int level=0;
        while(!stk.empty()){
            int size = stk.size();
            for(int i=0;i<size; i++){
                TreeNode* temp = stk.front();
                temp->val = levels[level][i];
                stk.pop();
                if(temp->left) stk.push(temp->left);
                if(temp->right) stk.push(temp->right);
            }
            level++;
        }
        return root;
    }
};