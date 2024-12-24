class Solution {
public:
int solve(int i, int target, vector<int>&nums, vector<vector<int>> &dp){
     if(i==0){
            if(nums[0]==0 && target==0) return 2;
            if(target==0) return 1;
            return nums[0]==target;
    }

    if(dp[i][target] != -1 ) return dp[i][target];
    int pick=0;
    if(nums[i] <= target) pick = solve(i-1, target-nums[i], nums, dp);
    int notpick = solve(i-1, target, nums, dp);
    return dp[i][target] = pick + notpick;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n; i++) total += nums[i];

        int t = (total-target) /2;
        vector<vector<int>> dp(n, vector<int>(t+1,-1));
        return solve(n-1, (total-target)/2, nums, dp);
    }
};