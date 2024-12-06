class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mini = arr[0];

        int sum=0;
        for(int i=1; i<n; i++){
            
            if(arr[i-1] > arr[i]){
                sum += arr[i-1]-mini;
                mini = arr[i];
            }
            mini = min(mini, arr[i]);
        }
        
        sum += arr[n-1]-mini;

        return sum;
    }
};