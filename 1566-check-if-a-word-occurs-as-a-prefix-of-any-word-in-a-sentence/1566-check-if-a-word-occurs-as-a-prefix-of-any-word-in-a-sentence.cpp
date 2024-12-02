class Solution {
public:
    int isPrefixOfWord(string sentence, string s) {
        int n = sentence.length();
        int m = s.length();

        
        
        int ans=0;
        int i=0;
        int count1=0;
        while(i<n){
            string count="";
            while(i<n && sentence[i]!=' '){
                count.push_back(sentence[i]);
                i++;
            }
            count1++;
            int j=0, k=0;
            while(j < count.length() && k<m){
                if(count[j] != s[k]){
                    break;
                }
                j++;
                k++;
            }
            if(j==s.length()){
                ans = count1;
                break;
            }
            i++;
        }
        return ans==0 ? -1 : ans;
    }
};