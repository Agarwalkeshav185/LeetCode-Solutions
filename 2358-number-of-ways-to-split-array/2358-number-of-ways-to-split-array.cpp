class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int total = 0;
        for(auto it : nums) total += it;

        long long int cnt=0;
        long long int ans=0;
        for(int i=0;i<n-1; i++){
            cnt += nums[i];
            if(cnt >= total-cnt) ans++;
        }
        return ans;
    }

};