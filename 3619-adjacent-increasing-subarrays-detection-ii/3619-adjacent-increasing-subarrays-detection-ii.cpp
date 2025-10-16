class Solution {
public:
    bool solve(vector<int>& nums, int k){
        int n = nums.size();
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int start = 0, last = n;
        while(start <= last){
            int mid = (start+last)/2;
            if(solve(nums, mid)){
                start = mid+1;
            }
            else last = mid-1;
        }
        return last;
    }
};