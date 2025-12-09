class Solution {
public:
    bool isPalindrome(string s){
        int n =s.length();
        int i = 0, j = n-1;
        while(i<j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        if(n<2) return ans;

        unordered_map<string, int> rev;

        for(int i=0;i<n; i++){
            string t = words[i];
            reverse(t.begin(), t.end());
            rev[t] = i;
        }

        for(int i=0;i<n; i++){
            for(int j=0; j <= words[i].length(); j++){
                string str1 = words[i].substr(0,j); // prefix
                string str2 = words[i].substr(j); // suffix

                if( rev.count(str1) && isPalindrome(str2) && rev[str1] != i){
                    ans.push_back({i, rev[str1]});
                }

                if(!str1.empty() && rev.count(str2) && isPalindrome(str1) &&  rev[str2] != i){
                    ans.push_back({rev[str2], i});
                } 
            }
        }

        return ans;
    }
};