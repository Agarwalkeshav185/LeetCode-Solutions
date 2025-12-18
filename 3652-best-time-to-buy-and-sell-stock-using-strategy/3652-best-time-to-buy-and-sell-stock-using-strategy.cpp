class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        // long long int ans=0;
        long long int sum = 0;
        for(int i=0;i<n; i++){
            sum += prices[i]*1LL*strategy[i];
        }
        long long int cnt=0;
        int start=0, mid = k/2, i = k/2;
        int end = k;
        for(int i= 0; i<n; i++){
            if(mid <= i && i < end) cnt += prices[i];
            else if(end <= i) cnt += prices[i]*1LL*strategy[i];
        }
        sum = max(sum, cnt);
        // cout<<sum<<endl;
        for(int i = k; i<n; i++){
            cnt += (prices[i-k]*1LL*strategy[i-k]);
            cnt -= prices[mid++];
            if(strategy[i] == -1){
                cnt += 2*prices[i];
            }
            else if(strategy[i] == 0){
                cnt += prices[i];
            }
            sum = max(sum, cnt);
        }
        return sum;
    }
};