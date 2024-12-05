class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int ans=0, j=0;
        for(int i=0; i<n; i++){
            if(prices[j] > prices[i]){
                j = i;
            }
            ans = max(ans, prices[i]- prices[j]);
        }

        return ans;
    }
};