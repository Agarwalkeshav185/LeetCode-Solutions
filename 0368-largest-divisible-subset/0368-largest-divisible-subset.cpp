class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int maxi=1, lastind=0;
        vector<int> dp(n,1), hash(n);
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[i] < 1+dp[j]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastind = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastind]);
        while(hash[lastind] != lastind){
            lastind = hash[lastind];
            temp.push_back(nums[lastind]);
        }
        return temp;
    }
};