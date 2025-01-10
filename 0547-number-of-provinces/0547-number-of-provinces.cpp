class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
        vis[node]=1;
        int n = adj.size();
        for(int i=0;i<n; i++){
            if(i!=node && adj[node][i] && !vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n; i++){
            if(!vis[i]){
                dfs(i,isConnected, vis);
                cnt++;
            }
        }
        return cnt;
    }
};