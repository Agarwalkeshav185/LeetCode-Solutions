class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==1) return {0};
            else return {1};
        }
        vector<int> count(n+1,0);
        int sum=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int leftZero = 0, rightOne = sum;

        // Score at split index 0 (no elements on left)
        count[0] = leftZero + rightOne;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) leftZero++;
            else rightOne--;
            count[i + 1] = leftZero + rightOne;
        }

        vector<int> ans;
        int maxi = *max_element(count.begin(), count.end());
        for(int i=0; i<=n; i++){
            if(count[i] == maxi) ans.push_back(i);
        }
        return ans;

    }
};