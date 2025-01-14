class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n,0);
        vector<int> ans(n,0);

        for(int i=0;i<n; i++){
            count[A[i]-1]++;
            count[B[i]-1]++;
            int cnt=0;
            for(int j=0;j<n; j++){
                if(count[j]==2) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};