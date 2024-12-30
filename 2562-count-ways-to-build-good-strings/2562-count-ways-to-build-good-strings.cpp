class Solution {
public:
int mod = 1e9 +7;
int solve(int start ,int low, int high, int zero, int one,vector<int> &dp){
    if(start > high) return 0;

    if(dp[start] != -1) return dp[start];
    int cnt=0;
    if(start >= low)
        cnt = 1;
    int ones = solve(start +one, low, high,zero,one, dp);
    int zeroes = solve(start + zero ,low, high, zero, one, dp);

    return dp[start] = (cnt+ones+zeroes) % mod;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return solve(0,low,high,zero,one,dp);
    }
};