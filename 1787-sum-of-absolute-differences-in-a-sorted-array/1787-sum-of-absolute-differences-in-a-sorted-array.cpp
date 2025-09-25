class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> count = nums;
        for(int i=1; i<n; i++){
            count[i] += count[i-1];
        }
        vector<int> ans;
        for(int i=0;i<n; i++){
            int sum = (nums[i]*(i+1) - count[i]) + ( (count[n-1] - count[i] )- nums[i]*(n-i-1)); 
            ans.push_back(sum);
        }
        return ans;
    }
};