/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        vector<vector<Node*>> levels;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            vector<Node*> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levels.push_back(level);
        }
        int n = levels.size();
        for(int i=0;i<n; i++){
            int m = levels[i].size();
            for(int j=0; j < m; j++){
                if(j < m-1) {
                    Node* tempi = levels[i][j];
                    tempi->next = levels[i][j+1];
                } 
                else {
                    levels[i][j]->next = NULL;
                }
            }
        }
        return root;

    }
};