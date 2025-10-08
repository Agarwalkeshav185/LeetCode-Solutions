class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        sort(worker.begin(), worker.end());

        priority_queue<pair<double, int>> pq;
        for(int i=0;i<n; i++){
            pq.push({profit[i], difficulty[i]});
        }
        int ans=0;
        int i = m-1;
        while(i >= 0 && !pq.empty()){
            int ind = pq.top().second;
            if(ind <= worker[i]) {
                ans += pq.top().first;
                i--;
            }
            else pq.pop();
        }
        return ans;

    }
};