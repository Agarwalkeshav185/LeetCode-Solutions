class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> count;

        for(auto it : nums){
            count[it]++;
        }
        vector<int> ans;
        for(auto &it : count){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};