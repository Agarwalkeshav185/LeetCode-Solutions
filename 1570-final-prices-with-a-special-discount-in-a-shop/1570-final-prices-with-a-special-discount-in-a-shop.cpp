class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        stack<int> stk;
        int i=n-1;
        stk.push(prices[i]);
        while(i>=0){
            while(!stk.empty() && stk.top() > prices[i]){
                stk.pop();
            }
            int a = prices[i];
            if(stk.empty() || i==n-1) prices[i] = prices[i];
            else prices[i] = prices[i] - stk.top();

            stk.push(a);
            i--;
        }
        return prices;
    }
};