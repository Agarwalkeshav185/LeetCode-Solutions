class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        string ans="";
        shifts[n-1] = shifts[n-1] % 26;
        for(int i=n-1; i>0; i--){
            shifts[i-1] += shifts[i]%26;
        }
        for(int i=0; i<n; i++){
            ans += (s[i]-'a' + shifts[i])%26 +'a';
        }

        return ans;
    }
};