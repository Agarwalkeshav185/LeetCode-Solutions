class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> count(1001, 0);
        int n = trips.size();
        for(int i=0; i<n; i++){
            int value = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            count[from] += value;
            count[to] -= value; 
        }

        for(int i = 1; i<1001; i++){
            count[i] += count[i-1];
        }
        for(int i=0;i<1001; i++){
            if(count[i] > capacity) return false;
        }
        return true;
    }
};