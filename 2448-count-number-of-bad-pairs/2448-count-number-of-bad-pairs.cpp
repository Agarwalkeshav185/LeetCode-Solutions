class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n =nums.size();
        unordered_map<long long , long long> count;
        long long ans=0;
        for(int i=0;i<n; i++){
            ans += i - count[nums[i]-i];
            count[nums[i]-i]++;
        }
        return ans;
    }
};