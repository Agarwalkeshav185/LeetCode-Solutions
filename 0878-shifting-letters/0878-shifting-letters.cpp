class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        string ans = s;

        long long int sum=0;
        for(int i=n-1; i>=0; i--){
            sum += shifts[i];
            int shift = sum%26;
            ans[i] = (s[i]-'a' + shift)%26 + 'a';
        }

        return ans;
    }
};