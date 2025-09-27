class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int score = 0;
        long long prefix = nums[n-1];
        if(nums[n-1]>0) score++;
        for(int i=n-2; i>=0 ; i--){ 
            prefix += nums[i];
            if(prefix > 0) score++;
        }
        return score;
    }
};