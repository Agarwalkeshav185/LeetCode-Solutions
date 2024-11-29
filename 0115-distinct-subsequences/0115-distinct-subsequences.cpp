class Solution {
public:
    // // Memoiation
    // int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
    //     if(j==0) return 1;
    //     if(i==0) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i-1]==t[j-1])
    //         return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s,t, dp);
    //     else 
    //         return dp[i][j] = solve(i-1, j, s,t, dp);
    // }
    // int numDistinct(string s, string t) {
    //     int n = s.length();
    //     int m = t.length();

    //     vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

    //     return solve(n, m, s, t, dp);
    // }

    // // Tabulaiton
    // int numDistinct(string s, string t) {
    //     int n = s.length();
    //     int m = t.length();

    //     vector<vector<int>> dp(n+1, vector<int> (m+1,0));
    //     // Base Case
    //     for(int j=0; j<=n; j++) dp[j][0] = 1;
        
    //     // Make Loops
    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(s[i-1]==t[j-1])
    //                 dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
    //             else 
    //                 dp[i][j] = dp[i-1][j];
    //         }
    //     }
    //     // Return the ans;
    //     return dp[n][m];
    // }

    // Space-Opitmization
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        // vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        vector<double> prev(m+1,0);
        // Base Case
        prev[0] = 1;
        
        // Make Loops
        for(int i=1; i<=n; i++){
            for(int j = m; j>0; j--){
                if(s[i-1]==t[j-1])
                    prev[j] = prev[j] + prev[j-1];
                else 
                    prev[j] = prev[j];
            }
        }
        // Return the ans;
        return prev[m];
    }
};
