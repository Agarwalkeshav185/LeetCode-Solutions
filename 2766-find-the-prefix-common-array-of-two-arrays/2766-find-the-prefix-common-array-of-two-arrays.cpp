class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n,0);
        vector<int> ans(n,0);
        int cnt=0;
        for(int i=0;i<n; i++){
            count[A[i]-1]++;
            if(count[A[i]-1] == 2) cnt++;
            count[B[i]-1]++;
            if(count[B[i]-1]==2) cnt++;
            ans[i] = cnt;
        }
        return ans;
    }
};