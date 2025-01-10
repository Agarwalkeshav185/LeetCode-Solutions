class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n; i++){
            for(int j=0;j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[] = {-1,0,0,1};
        int delcol[] = {0,-1,1,0};
        int time=0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int tame = q.front().second;
            vis[x][y] = 1;
            q.pop();
            time = max(time, tame);
            for(int k=0;k<4; k++){
                int i = x + delrow[k];
                int j = y + delcol[k];
                if(i>=0 && i<n && j>=0 &&j<m && !vis[i][j] && grid[i][j]==1){
                    q.push({{i,j},tame+1});
                    grid[i][j] = 2;
                }
            }
        }

        for(int i=0;i<n; i++){
            for(int j=0;j<m; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};