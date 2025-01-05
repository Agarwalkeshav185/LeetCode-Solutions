class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int m = s.length();
        vector<int> prefix(m+1,0);

        string ans=s;
        for(int i=0;i<n; i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = (shifts[i][2] ==1) ? 1 :-1;

            prefix[start] += direction;
            if(end+1 < m){
                prefix[end+1] -= direction;
            }
        }
        int cnt=0;
        for(int i=0;i<m; i++){
            cnt += prefix[i];

            int pos = cnt % 26;
            if(pos <0){
                ans[i] = (s[i]-'a' + 26 + pos)%26 +'a';
            }
            else{
                ans[i] = (s[i]-'a' + pos)%26 +'a';
            }
        }
        return ans;
    }
};