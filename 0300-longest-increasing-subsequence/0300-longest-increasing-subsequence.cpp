class Solution {
public:
    // // Memoiation
    // int solve(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp){
    //     if(ind == nums.size()) return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int pick = 0, notpick = 0;
    //     if(prev == -1 || nums[prev] < nums[ind])
    //         pick = 1 + solve(ind+1, ind, nums, dp);
        
    //     notpick = solve(ind+1, prev , nums, dp);

    //     return dp[ind][prev+1] = max(pick ,notpick);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n =  nums.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    //     return solve(0, -1, nums, dp);
    // }

    // // Tabulation
    // int lengthOfLIS(vector<int>& nums) {
    //     int n =  nums.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
    //     for(int ind = n-1; ind>=0; ind--){
    //         for(int prev = ind-1; prev >= -1; prev--){
    //             int notpick = dp[ind+1][prev+1];
    //             int pick = 0;
    //             if(prev==-1 || nums[ind] > nums[prev]){
    //                 pick = 1 + dp[ind+1][ind+1];
    //             }
    //             dp[ind][prev+1] = max(pick, notpick);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // Space-Optimization
    int lengthOfLIS(vector<int>& nums) {
        int n =  nums.size();
        vector<int> front(n+1,0), cur(n+1, 0);
        
        for(int ind = n-1; ind>=0; ind--){
            for(int prev = ind-1; prev >= -1; prev--){
                int notpick = front[prev+1];
                int pick = 0;
                if(prev==-1 || nums[ind] > nums[prev]){
                    pick = 1 + front[ind+1];
                }
                cur[prev+1] = max(pick, notpick);
            }
            front = cur;
        }
        return front[0];
    }
};