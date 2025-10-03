class Solution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        // { height, { row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
        
        for(int i=0;i<m; i++){
            pq.push({heights[0][i],{0,i}});
            vis[0][i] = 1;
            pq.push({heights[n-1][i],{n-1, i}});
            vis[n-1][i] = 1;
        }
        for(int j=1;j<n-1; j++){
            pq.push({heights[j][0],{j,0}});
            vis[j][0] = 1;
            pq.push({heights[j][m-1],{j,m-1}});
            vis[j][m-1] = 1;
        }

        int delrow[] = {-1,0,0,1};
        int delcol[] = {0,-1,1,0};
        int ans=0;
        while(!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int height = pq.top().first;
            pq.pop();
            
            for(int k=0; k<4; k++){
                int x = i + delrow[k];
                int y = j + delcol[k];

                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                    if(heights[x][y] <= height){
                        ans += height - heights[x][y];
                    }
                    vis[x][y] = 1;
                    int maxi = max(height, heights[x][y]);
                    pq.push({maxi,{x,y}});
                }
            }

        }
        return ans;
    }
};