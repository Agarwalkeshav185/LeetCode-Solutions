class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> pq;
        for(int i=0;i<n; i++){
            pq.push({nums[i], i});
        }

        for(int i=0;i<k; i++){
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();
            pq.push({a*multiplier, b});
        }
        while(!pq.empty()){
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return nums;
    }
};