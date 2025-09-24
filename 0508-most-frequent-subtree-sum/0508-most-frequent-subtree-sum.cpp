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
    int inorder(TreeNode* root, map<int,int, greater<int>>& count){
        if(root== NULL) return 0;
        int sum = root->val;
        sum += inorder(root->left, count);
        sum += inorder(root->right, count);
        count[sum]++;
        return sum;

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int, greater<int>> count;
        priority_queue<pair<int, int>> pq;
        inorder(root, count);
        vector<int> ans;
        
        for(auto it : count){
            pq.push({it.second, it.first});
        }
        int counti = pq.top().first;
        while(!pq.empty()){
            if(counti != pq.top().first){
                break;
            }
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};