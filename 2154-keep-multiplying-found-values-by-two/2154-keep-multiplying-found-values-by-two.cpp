class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> count(1001, 0);
        for(auto it : nums){
            count[it] = 1;
        }
        while( original <= 1000 && count[original] != 0){
            original *= 2;
        }
        return original;
    }
};