class Solution {
public:
    bool isprefixandsuffix(string str1, string str2){
        int n = str1.size(), m = str2.size();
        if(n > m) return false;
        for(int i=0;i<n; i++){
            if(str1[i] != str2[i] || str1[n-i-1] != str2[m-1-i]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0;i<n; i++){
            for(int j=i+1;j<n; j++){
                if(i != j && isprefixandsuffix(words[i], words[j])) cnt++;
            }
        }
        return cnt;
    }
};