class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(1000002,0);
        for(int i=0; i<n; i++){
            count[nums[i]]++;
        }
        vector<int> ans;
        if(count[1] == 0 && count[0]==1) ans.push_back(0);
        for(int i=1;i<=1000000; i++){
            if(count[i-1] == 0 && count[i+1] == 0 && count[i]==1) ans.push_back(i);
        }
        return ans;
    }
};