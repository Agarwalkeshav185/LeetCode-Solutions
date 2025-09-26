class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n && nums[i]==1){
            i++;
        }
        int cnt=0;
        while(i<n-2){
            if(nums[i] == 0){
                cnt++;
                // cout<<nums[i]<<" ";
                nums[i] = !nums[i];
                // cout<<nums[i]<<endl;
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
                // cout<<" "<< i+2<<" "<<nums[i+2]<<endl;
            }
            i++;
        }
        // cout<<endl;
        for(int i=0;i<n; i++){
            // cout<<nums[i]<<" ";
            if(nums[i] == 0) return -1;
        }
        return cnt;
    }
};