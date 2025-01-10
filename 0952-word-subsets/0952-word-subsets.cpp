class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();

        vector<int> count2(26,0);
        for(int i=0;i<m; i++){
            string word = words2[i];
            vector<int> count(26,0);
            for(int j=0;j<word.length(); j++){
                count[word[j]-'a']++; 
            }
            for(int j=0;j<26; j++){
                count2[j] = max(count2[j], count[j]);
            }
        }

        vector<string> ans;
        for(int i=0;i<n; i++){
            string word = words1[i];
            vector<int> count(26,0);
            for(int j=0;j<word.length(); j++){
                count[word[j]-'a']++;
            }
            bool flag = true;
            for(int j=0;j<26; j++){
                if(count[j] < count2[j]) flag = false;
            }
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};