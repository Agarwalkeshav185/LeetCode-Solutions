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
    int maxfreq = 0;
    int inorder(TreeNode* root, unordered_map<int,int>& count){
        if(root== NULL) return 0;
        int sum = root->val;
        sum += inorder(root->left, count);
        sum += inorder(root->right, count);
        count[sum]++;
        maxfreq = max(maxfreq, count[sum]);
        return sum;

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> count;
        inorder(root, count);
        vector<int> ans;
        
        for(auto it : count){
            if(maxfreq == it.second){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};