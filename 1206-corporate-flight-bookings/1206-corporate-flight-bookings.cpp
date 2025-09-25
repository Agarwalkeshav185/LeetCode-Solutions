class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size();
        vector<int> ans(n, 0);
        for(int i=0; i<m; i++){
            int seats = bookings[i][2];
            int from = bookings[i][0];
            int to = bookings[i][1];
            ans[from-1] += seats;
            if(to < n) ans[to] -= seats;
        }
        for(int i=1; i<n; i++){
            ans[i] += ans[i-1];
        }
        return ans;

    }
};