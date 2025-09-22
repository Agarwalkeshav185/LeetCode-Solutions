class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101, 0);
        for(int num : nums){
            count[num]++;
        }
        int maxi = *max_element(count.begin(), count.end());
        int ans=0;
        for(auto it : count){
            if(it == maxi) ans += maxi;
        }
        return ans;
    }
};