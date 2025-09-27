class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        vector<vector<int>> count;

        int n = points.size();
        count.push_back(points[0]);
        for(int i=1; i<n; i++){
            if(( count.back()[0] <= points[i][0] && points[i][0] <= count.back()[1]) || 
                (count.back()[0] <= points[i][1] && points[i][1] <= count.back()[1])) {
                    count.back()[0] = max(count.back()[0], points[i][0]);
                    count.back()[1] = min(count.back()[1], points[i][1]);
            }
            else count.push_back(points[i]);
        }

        return count.size();
    }
};