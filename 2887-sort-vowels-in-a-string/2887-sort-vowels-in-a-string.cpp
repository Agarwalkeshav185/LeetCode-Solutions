class Solution {
public:
    bool isVowel(char & ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }
    string sortVowels(string s) {
        int n = s.length();
        vector<char> count;
        for(int i=0;i<n; i++){
            if(isVowel(s[i])){
                count.push_back(s[i]);
            }
        }
        sort(count.begin(), count.end());
        int j=0;
        for(int i=0;i<n; i++){
            if(isVowel(s[i])){
                s[i] = count[j++];
            }
        }
        return s;

    }
};