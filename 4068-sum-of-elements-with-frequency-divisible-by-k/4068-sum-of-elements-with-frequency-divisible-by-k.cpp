class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for(auto it : nums){
            count[it]++;
        }
        int ans = 0;
        for(auto it : count){
            if(it.second%k ==0){
                ans += it.first * it.second;
            }
        }
        return ans;
    }
};