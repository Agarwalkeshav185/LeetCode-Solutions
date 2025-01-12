class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int, int>, int>> q;
        for(int i=0;i<n; i++){
            for(int j=0;j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1,0,0,1};
        int delcol[] = {0,-1,1,0};

        while(!q.empty()){
            int nodex = q.front().first.first;
            int nodey = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            vis[nodex][nodey] = 1;

            for(int i=0;i<4; i++){
                int x = nodex + delrow[i];
                int y = nodey + delcol[i];
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && mat[x][y]==1){
                    q.push({{x,y}, dis+1});
                    vis[x][y] = 1;
                    ans[x][y] = dis+1;
                }
            }
        }
        return ans;
    }
};