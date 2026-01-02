class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        for(auto it : nums){
            count[it]++;
        }
        for(auto it : count){
            if(it.second == (n/2)) return it.first;
        }
        return -1;
    }
};