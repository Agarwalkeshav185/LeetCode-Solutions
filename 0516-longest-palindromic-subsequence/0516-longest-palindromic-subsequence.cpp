class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.length();
        vector<int> prev(n+1, 0) , temp(n+1, 0);
        string s1 = s;
        reverse(s.begin(), s.end());

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s[j-1]){
                    temp[j] = 1+ prev[j-1];
                }
                else temp[j] = max(prev[j], temp[j-1]);
            }
            prev = temp;
        }

        return prev[n];
    }
};