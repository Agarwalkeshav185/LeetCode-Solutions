class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.length();

        int cnt=0;
        for(int i=0;i<n; i++){
            if(pref == words[i].substr(0,m)) cnt++;
        }
        return cnt;
    }
};