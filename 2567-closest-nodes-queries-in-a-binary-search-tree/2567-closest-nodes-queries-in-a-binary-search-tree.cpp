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

// Brute Force using Tree Traverse
    // vector<int> solve(TreeNode* root, int min, int max, int target){
    //     if(root== NULL) return {min, max};
    //     if(root->val == target) return {target, target};
    //     if(root->val > target) return solve(root->left, min, root->val, target);
    //     return solve(root->right, root->val, max, target);
    // }
    // vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    //     vector<vector<int>> ans;
    //     int n = queries.size();

    //     for(int i=0;i<n; i++){
    //         vector<int> temp = solve(root, INT_MIN, INT_MAX, queries[i]);
    //         temp[0] = temp[0] == INT_MIN ? -1 : temp[0];
    //         temp[1] = temp[1] == INT_MAX ? -1 : temp[1];
    //         ans.push_back(temp);;
    //     }
    //     return ans;
    // }
    void inorder(TreeNode* root, vector<int>&inord){
        if(root== NULL) return;
        inorder(root->left, inord);
        inord.push_back(root->val);
        inorder(root->right, inord);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries){
        vector<int> inord;
        inorder(root, inord);

        int n = queries.size();
        vector<vector<int>> ans;
        for(int i=0;i<n; i++){
            vector<int> temp;
            int target = queries[i];
            auto it = lower_bound(inord.begin(), inord.end(), target);
            if (it == inord.begin()) {
                if (*it == target) temp.push_back(*it);
                else temp.push_back(-1);
            } else {
                if (it != inord.end() && *it == target) temp.push_back(*it);
                else temp.push_back(*(it - 1));
            }

            auto it2 = lower_bound(inord.begin(), inord.end(), target);
            if (it2 == inord.end()) temp.push_back(-1);
            else temp.push_back(*it2);

            ans.push_back(temp);
        }
        return ans;
    }
};