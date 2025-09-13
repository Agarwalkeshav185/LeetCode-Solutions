class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch == 'o' || ch=='u';
    }
    int maxFreqSum(string s) {
        vector<int> count(27,0);
        int maxiVowel = 0;
        int maxiCon = 0;
        int n = s.length();
        for(int i=0;i<n; i++){
            count[s[i]-'a']++;
        }
        for(char i='a'; i<='z'; i++){
            if(isVowel(i)) maxiVowel = max(maxiVowel, count[i-'a']);
            else maxiCon = max(maxiCon, count[i-'a']);
        }
        return maxiVowel + maxiCon;

    }
};