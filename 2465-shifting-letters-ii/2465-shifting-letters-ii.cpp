class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int m = s.length();
        vector<int> prefix(m+1,0);
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
            prefix[i] = cnt;
        }

        for(int i=0;i<m; i++){
            int pos = prefix[i] % 26;
            if(pos <0){
                s[i] = (s[i]-'a' + 26 + pos)%26 +'a';
            }
            else{
                s[i] = (s[i]-'a' + pos)%26 +'a';
            }
        }

        return s;
    }
};