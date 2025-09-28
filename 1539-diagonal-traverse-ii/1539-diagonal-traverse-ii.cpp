class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;

        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j = 0; j<nums[i].size(); j++){
                pq.push({i+j , {j, nums[i][j]}});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second.second);
            pq.pop();
        }
        return ans;
    }
};