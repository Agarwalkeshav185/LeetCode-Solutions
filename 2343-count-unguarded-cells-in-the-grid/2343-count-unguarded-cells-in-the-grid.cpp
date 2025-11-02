class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g = guards.size();
        int w = walls.size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i=0;i<g; i++){
            dp[guards[i][0]][guards[i][1]] = 1;
        }
        for(int i=0;i<w; i++){
            dp[walls[i][0]][walls[i][1]] = 2;
        }
        
        bool flag = false;
        for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
                if(dp[i][j]==1) {
                    flag = true;
                }
                if(flag && dp[i][j]==0) dp[i][j] = -1;
                else if(dp[i][j]==2) flag = false;
            }
            flag = false;
            for(int j = n-1; j>=0; j--){
                if(dp[i][j]==1) {
                    flag = true;
                }
                if(flag && dp[i][j]==0) dp[i][j] = -1;
                else if(dp[i][j]==2) flag = false;
            }
            flag = false;
        }
        for(int j=0;j<n; j++){
            for(int i=m-1; i>=0; i--){
                if(dp[i][j]==1) flag = true;
                if(flag && dp[i][j]==0) dp[i][j] = -1;
                else if(dp[i][j]==2) flag = false;
                
            }
            flag = false;
            for(int i=0; i<m; i++){
                if(dp[i][j]==1) flag = true;
                if(flag && dp[i][j]==0) dp[i][j] = -1;
                else if(dp[i][j]==2) flag = false;
            }
            flag = false;
        }

        int cnt=0;
        for(int i=0;i<m ;i++){
            for(int j=0;j<n; j++){
                if(dp[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};