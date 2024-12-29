class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = n/3;
        int first = INT_MIN, second = INT_MIN;

        int i=0;
        while(i<n){
            int a = nums[i];
            int cnt=0;
            while(i<n && nums[i]==a) {
                i++;
                cnt++;
            }
            if(cnt > target && first == INT_MIN) first = a;
            else if(cnt > target && first != second) second = a;
        }
        if(first == INT_MIN) return {};
        else if(first != INT_MIN && second ==INT_MIN) return {first};
        else return {first, second};
    }
};