class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> count(value, 0);
        int ans=0;
        for(int i=0;i<n; i++){
            // count[abs(nums[i])%value]++;
            if(nums[i]>=0 )count[abs(nums[i])%value]++;
            else if(nums[i]<0){
                int valToAdd = ceil(1.0*abs(nums[i])/value);
                count[(nums[i]+valToAdd*value)%value]++;
            }
        }
        int i=0;
        while(count[i%value] != 0){
            count[i%value]--;
            i++;
        }
        return i;
    }
};