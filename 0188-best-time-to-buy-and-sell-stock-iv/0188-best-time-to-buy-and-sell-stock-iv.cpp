class Solution {
public:
    // // Memoiation
    // int solve(int i, int trans, int k, vector<int> &prices, vector<vector<int>> &dp){
    //     if(i==prices.size() || trans == 2*k) return 0;
    //     if(dp[i][trans] !=-1) return dp[i][trans];
    //     if(trans%2==0){
    //         return dp[i][trans] = max(-prices[i]+ solve(i+1, trans+1,k,prices ,dp), solve(i+1, trans, k, prices, dp));
    //     }
    //     else{
    //         return dp[i][trans] = max(prices[i]+solve(i+1, trans+1, k, prices, dp), solve(i+1, trans, k, prices, dp));
    //     }
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(2*k+1,-1));
    //     return solve(0, 0, k,prices, dp);
    // }

    // // Tabulation
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
    //     // // Base Cases
    //     // for(int trans = 0; trans < 2*k ; trans++){
    //     //       dp[n][trans] = 0;
    //     // }
    //     // for(int i=0; i<=n; i++){
    //     //     dp[i][2*k]=0;
    //     // }
    //     for(int i = n-1; i>=0; i--){
    //         for(int trans=2*k-1; trans>=0; trans--){
    //             if( trans%2 == 0 ){
    //                 dp[i][trans] = max(-prices[i]+dp[i+1][trans+1], dp[i+1][trans]);
    //             }
    //             else{
    //                 dp[i][trans] = max(prices[i]+ dp[i+1][trans+1], dp[i+1][trans]);
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }

    // Space-Optimization
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2*k+1, 0), cur(2*k+1, 0);
        // // Base Cases
        // for(int trans = 0; trans < 2*k ; trans++)
        //       prev[trans] = 0;
        // prev[2*k] = 0;
        // cur[2*k] = 0;
        for(int i = n-1; i>=0; i--){
            for(int trans=2*k-1; trans>=0; trans--){
                if( trans%2 == 0 )
                    cur[trans] = max(-prices[i]+ prev[trans+1],  prev[trans]);
                else
                    cur[trans] = max(prices[i]+  prev[trans+1],  prev[trans]);
            }
            prev = cur;
        }
        return prev[0];
    }
};