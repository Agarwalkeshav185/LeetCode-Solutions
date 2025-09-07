class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);
        int cnt = n/2;
        for(int i=0;i<n/2; i++){
            ans[i] = -cnt;
            ans[n-i-1] = cnt;
            cnt--;
        }
        return ans;
    }
};