class Solution {
public:
    // // Memoiation
    // int solve(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> & dp){
    //     if(cap==0) return 0;
    //     if(ind == prices.size()) return 0;

    //     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    //     if(buy){
    //         return dp[ind][buy][cap] = max(-prices[ind] + solve(ind+1, 0, cap, prices, dp),
    //                                   solve(ind+1, 1, cap, prices, dp));
    //     }
    //     else {
    //         return dp[ind][buy][cap] = max(prices[ind] + solve(ind+1, 1, cap-1, prices, dp),
    //                                  solve(ind+1, 0, cap, prices, dp));
    //     }
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
    //     return solve(0, 1, 2, prices, dp);
    // }

    // // Tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
    //     // // Base Cases
    //     // for(int buy=0; buy<=1; buy++){
    //     //     for(int cap=0; cap<3; cap++){
    //     //         dp[n][buy][cap] = 0;
    //     //     }
    //     // }
    //     // for(int ind=0; ind<=n;  ind++){
    //     //     for(int buy=0; buy<=1; buy++){
    //     //         dp[ind][buy][0] = 0;
    //     //     }
    //     // }
    //     for(int ind = n-1; ind>=0 ; ind--){
    //         for(int buy=0; buy<=1; buy++){
    //             for(int cap=1; cap<=2; cap++){
    //                 if(buy){
    //                     dp[ind][buy][cap] = max(-prices[ind]+ dp[ind+1][0][cap], dp[ind+1][1][cap]);
    //                 }
    //                 else
    //                     dp[ind][buy][cap] = max(prices[ind]+ dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }

    // Space-Optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3,0)), cur(2, vector<int>(3,0));
        // // Base Cases
        // for(int buy=0; buy<=1; buy++){
        //     for(int cap=0; cap<3; cap++){
        //         prev[buy][cap] = 0;
        //     }
        // }
        //     for(int buy=0; buy<=1; buy++){
        //         prev[buy][0] =0;
        //     }
        for(int ind = n-1; ind>=0 ; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy){
                        cur[buy][cap] = max(-prices[ind]+ prev[0][cap], prev[1][cap]);
                    }
                    else
                        cur[buy][cap] = max(prices[ind]+ prev[1][cap-1], prev[0][cap]);
                }
            }
            prev = cur;
        }
        return prev[1][2];
    }
};