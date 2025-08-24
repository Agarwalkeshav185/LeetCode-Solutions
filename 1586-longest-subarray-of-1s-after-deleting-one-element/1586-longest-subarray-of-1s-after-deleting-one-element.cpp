class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;

        int i=0, j=0;
        int sum=0;
        int maxsum = INT_MIN;
        while(j<n){
            if(nums[j] == 0) zeroCount++;
            sum++;
            while(i<j && zeroCount > 1){
                sum--;
                if(nums[i] == 0) zeroCount--;
                i++;
            }
            if(zeroCount <=1 ) maxsum = max(maxsum, sum);
            j++;
        }
        return maxsum-1;
    }
};