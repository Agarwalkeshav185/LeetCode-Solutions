class Solution {
public:
    void solve(vector<int>& nums, int ind,vector<int>& arr, set<vector<int>>& ans){
        if(ind >= nums.size()){
            ans.insert(arr);
            return;
        }
        solve(nums, ind+1, arr, ans);

        arr.push_back(nums[ind]);
        solve(nums, ind+1, arr, ans);
        arr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans1;
        sort(nums.begin(), nums.end());
        vector<int> arr;

        solve(nums, 0, arr, ans1);
        vector<vector<int>> ans;
        for(auto it : ans1){
            ans.push_back(it);
        }
        return ans;
    }
};