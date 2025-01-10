class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int delrow[] = {-1,0,0,1};
        int delcol[] = {0,-1,1,0};
        int orignal = image[sr][sc];
        vector<vector<int>> vis(n,vector<int> (m,0));

        queue<pair<int, int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = color;
            vis[row][col]=1;

            for(int i=0;i<4; i++){
                int x = row + delrow[i];
                int y = col + delcol[i];
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] &&  image[x][y] == orignal){
                    q.push({x,y});
                    vis[x][y] = 1;
                    image[x][y] = color;
                }
            }
        }
        
        return image;
    }
};