class Solution {
public:
    // // Memoiation
    // int solve(int i, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp){
    //     if(i >= prices.size())return 0;
    //     if(dp[i][buy]!= -1) return dp[i][buy];
    //     if(buy){
    //         return dp[i][buy] = max(-prices[i] + solve(i+1, 0, prices, fee, dp), solve(i+1, 1, prices, fee, dp));
    //     }
    //     else{
    //         return dp[i][buy] = max(prices[i] - fee + solve(i+1, 1, prices, fee, dp), solve(i+1, 0, prices, fee, dp));
    //     }
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2,-1));
    //     return solve(0, 1, prices, fee, dp);
    // }

    // Tabulation
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int i=n-1; i>=0; i--){
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i] - fee + dp[i+1][1], dp[i+1][0]);
        }
        return dp[0][1];
    }
};