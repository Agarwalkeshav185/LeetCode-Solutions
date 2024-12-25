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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> stk;
        stk.push(root);
        vector<int> ans;
        while(!stk.empty()){
            int n = stk.size();
            int maxi = INT_MIN;
            for(int i=0;i<n; i++){
                TreeNode* temp = stk.front();
                stk.pop();
                maxi = max(maxi, temp->val);
                if(temp->left) stk.push(temp->left);
                if(temp->right) stk.push(temp->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};