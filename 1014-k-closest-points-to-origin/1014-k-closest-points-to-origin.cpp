class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        for(int i=0;i<n; i++){
            double dist = sqrt(points[i][0]*1.0*points[i][0] + points[i][1]*1.0*points[i][1]);
            pq.push({dist, i});
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};