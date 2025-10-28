class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        vector<int> laser(n,0);
        for(int i=0;i<n; i++){
            int cnt=0;
            for(int j=0; j<m; j++){
                if(bank[i][j] == '1') cnt++;
            }
            laser[i] = cnt; 
        }
        int i=0;
        int ans = 0;
        while(i<n){
            int prev = laser[i];
            i++;
            while(i<n && laser[i] == 0){
                i++;
            }
            if(i<n) {
                int cur = laser[i];
                ans += cur*prev;
            }
        }
        return ans;
    }
};