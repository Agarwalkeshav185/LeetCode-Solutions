class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans= target[n-1];
        for(int i=n-2; i>=0; i--){
            if(target[i]>=target[i+1]){
                ans += target[i]-target[i+1];
            }
        }
        return ans;
    }
};