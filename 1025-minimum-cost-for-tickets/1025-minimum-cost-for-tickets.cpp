class Solution {
public:

int solve(int ind, vector<int> & days, vector<int> &costs, vector<int>& dp){
    if(ind >= days.size())
        return 0;

    if(dp[ind] != -1) return dp[ind];

    int one = costs[0] + solve(ind+1, days, costs, dp);

    int next = ind;
    while(next < days.size() && days[next] < days[ind] +7) next++;
    int seven = costs[1] + solve(next, days, costs, dp);

    while(next<days.size() && days[next] < days[ind]+30) next++;
    int thirty = costs[2] + solve(next, days, costs, dp);

    return dp[ind] = min(one, min(seven, thirty));

}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1);
        return solve(0, days, costs, dp);
    }
};