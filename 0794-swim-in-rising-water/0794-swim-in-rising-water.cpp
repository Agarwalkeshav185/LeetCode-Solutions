class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0], {0,0}});
        visited[0][0] = 1;

        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,-1,1,0};

        int ans = INT_MIN;

        while(!pq.empty()){
            int value = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            ans = max(ans, value);
            pq.pop();

            if(row == n-1 && col == n-1) return ans;

            for(int i=0; i<4; i++){
                int r = row + dr[i];
                int c = col + dc[i];
                if(r>=0 && r<n && c>=0 && c<n && visited[r][c]==0){
                        pq.push({grid[r][c], {r,c}});
                        visited[r][c] = 1;
                }
            }
        }
        return ans;
    }
};