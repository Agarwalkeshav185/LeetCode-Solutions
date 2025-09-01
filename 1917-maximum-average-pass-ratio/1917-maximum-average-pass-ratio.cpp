class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        int n = classes.size();
        for(int i=0;i<n; i++){
            double a = classes[i][0] + 1;
            double b = classes[i][1] + 1;
            pq.push({ a/b - (classes[i][0]*1.00000)/classes[i][1], i});
        }
        // pair<double, int> a = pq.top();
        // classes[a.second][1] += 1;
        // classes[a.second][0] += 1;
        while(extraStudents--){
            pair<double, int> it = pq.top();
            pq.pop();
            int ind = it.second;
            classes[ind][1]++;
            classes[ind][0]++;
            double diff = ((classes[ind][0]+1)*1.0)/(classes[ind][1]+1) - ((classes[ind][0]*1.0)/classes[ind][1]);
            
            pq.push({diff, ind});
        }

        double ans = 0;
        for(int i=0;i<n; i++){
            ans += (classes[i][0]*1.00000)/classes[i][1];
        }
        return ans/n;
    }
};