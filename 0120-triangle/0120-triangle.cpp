class Solution {
public:
    // // Memoiation 
    // int solve(int i, int j, int &n, vector<vector<int>> & triangle, vector<vector<int>>& dp){
    //     if(i==n-1) return triangle[n-1][j];
    //     if(j>i) return INT_MAX;

    //     if(dp[i][j] != -1) return dp[i][j];
    //     long long int down = triangle[i][j] + solve(i+1, j, n, triangle, dp);
    //     long long int right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);

    //     return dp[i][j] = min(down, right);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int row = triangle.size();
    //     int col = triangle[row-1].size();
    //     vector<vector<int>> dp(row, vector<int>(col ,-1));
    //     return solve(0,0, row, triangle, dp);
    // }


    // // Tabulation
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int row = triangle.size();
    //     int col = triangle[row-1].size();
    //     vector<vector<int>> dp(row, vector<int>(col,0));

    //     for(int j=0; j<col; j++) dp[row-1][j] = triangle[row-1][j];

    //     for(int i= row-2; i>=0; i--){
    //         for(int j = i; j>=0; j--){
    //             int d = INT_MAX, dg = INT_MAX;
    //             d = triangle[i][j] + dp[i+1][j];
    //             dg = triangle[i][j] + dp[i+1][j+1];

    //             dp[i][j] = min(d,dg);
    //         }
    //     }

    //     return dp[0][0];
    // }

    // Space-Optimization
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();

        vector<int> prev(col,0);
        for(int j=0; j<col; j++) prev[j] = triangle[row-1][j];

        for(int i= row-2; i>=0; i--){
            vector<int> temp(col,0);
            for(int j = i; j>=0; j--){
                
                int d = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];

                temp[j] = min(d,dg);
            }
            prev = temp;
        }

        return prev[0];
    }
};