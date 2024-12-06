class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        sort(banned.begin(), banned.end());

        int cnt=0;
        int sum=0;
        int j=0;
        for(int i=1; i<=n; i++){
            if(j<m && i==banned[j]){
                int x = banned[j];
                while(j<m && x== banned[j]) j++;
                continue;
            }
            
            sum += i;
            if(sum <= maxSum)cnt++;
            if(sum >= maxSum) return cnt;
            
        }
        return cnt;
    }
};