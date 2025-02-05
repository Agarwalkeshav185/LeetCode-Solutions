class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int cnt=0;
        vector<int> count(26,0);
        for(int i=0;i<n; i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
            if(s1[i] != s2[i])  cnt++;
        }
        
        for(int i=0;i<26; i++){
            if(count[i]!=0) return false;
        }
        if(cnt == 0 || cnt ==2) return true;
        return false;
    }
};