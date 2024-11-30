class Solution {
public:
    // // Tabulation
    // int minDistance(string s1, string s2) {
    //     int n = s1.length();
    //     int m = s2.length();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    //     for(int i=0;i<=n; i++) dp[i][0] = i;
    //     for(int i=0; i<=m; i++) dp[0][i] = i;
    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(s1[i-1] == s2[j-1])
    //                 dp[i][j] = dp[i-1][j-1];
    //             else 
    //                 dp[i][j] = min( 1+dp[i-1][j], min( 1+dp[i-1][j-1], 1+dp[i][j-1] ));
    //         }
    //     }
    //     return dp[n][m];
    // }

    // Space-Optimization
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int> prev(m+1,0), temp(m+1,0);

        for(int i=0; i<=m; i++) prev[i] = i;
        
        for(int i=1; i<=n; i++){
            temp[0] = i;
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])
                    temp[j] = prev[j-1];
                else 
                    temp[j] = min( 1+prev[j], min( 1+prev[j-1], 1+temp[j-1] ));
            }
            prev = temp;
        }
        return prev[m];
    }
};