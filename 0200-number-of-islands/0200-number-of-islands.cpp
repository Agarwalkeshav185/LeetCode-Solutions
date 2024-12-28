class Solution {
public:
    void traversal(int i, int j, vector<vector<bool>>& vis, vector<vector<char>> & grid){
        vis[i][j] = 1;
        queue< pair<int, int>> stk;
        stk.push({i,j});
        vector<pair<int, int>> dp = {
            {-1,0}, {0,-1}, {0,1}, {1,0}
        };
        while(!stk.empty()){
            pair<int, int> temp = stk.front();
            cout<<temp.first<<" "<<temp.second<<endl;
            stk.pop();
            for(auto it:dp){
                int a = temp.first + it.first;
                int b = temp.second + it.second;
                if(a >=0 && a<grid.size() && b>=0 && b<grid[i].size() && !vis[ a ][ b ] && grid[a][b]=='1'){
                    stk.push({a,b});
                    vis[a][b] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n; i++){
            for(int j=0;j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    traversal(i,j,vis,grid);
                    cnt++;
                } 
            }
        }

        return cnt;
    }
};