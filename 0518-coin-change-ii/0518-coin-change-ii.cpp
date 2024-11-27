class Solution {
public:

    // int solve(int ind, int target, vector<int>& coins, vector<vector<int>> &dp){
    //     if(ind==0){
    //         return (target % coins[0] == 0);
    //     }
    //     if(dp[ind][target] !=-1) return dp[ind][target];
    //     int notpick = solve(ind-1, target, coins, dp);
    //     int pick = 0;
    //     if(coins[ind]<= target)
    //         pick = solve(ind, target-coins[ind], coins, dp);
    //     return dp[ind][target] = pick + notpick;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //     return solve(n-1, amount, coins, dp);
    // }


    int change(int amount, vector<int>& coins){
        long long int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0)
                dp[0][t] = 1;
            else dp[0][t] = 0;
        }

        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target <= amount; target++){
                long long int notpick = dp[ind-1][target];
                long long int pick = 0;
                if(coins[ind] <= target) 
                    pick = dp[ind][target - coins[ind]];
                dp[ind][target] = notpick + pick;
            }
        }
        return (int)(dp[n-1][amount]);
    }
};