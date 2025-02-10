class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int n = s.length();
        for(int i=0;i<n; i++){
            if( '0' <=s[i] && s[i]<='9'){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};