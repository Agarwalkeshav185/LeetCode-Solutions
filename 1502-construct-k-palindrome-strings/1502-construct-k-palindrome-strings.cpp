class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n < k) return false;
        vector<int> count(26,0);
        for(int i=0; i<n; i++){
            count[s[i]-'a']++;
        }
        int cnt=0;
        for(int i=0; i<26; i++){
            if(count[i]%2 == 1) cnt++;
        }
        if(cnt > k) return false;
        return true;
    }
};