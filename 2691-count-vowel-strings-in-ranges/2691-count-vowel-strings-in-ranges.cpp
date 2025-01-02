class Solution {
public:
    bool isvowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u') return 1;
        return 0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if( isvowel(words[i][0]) && isvowel(words[i][words[i].size()-1])){
                cnt++;
            }
            prefix[i] = cnt;
        }
        int m = queries.size();
        vector<int> ans(m,0);
        for(int i=0;i<m ;i++){
            int a = queries[i][1];
            int b = queries[i][0];
            if( a == b ){
                ans[i] = isvowel(words[a][0]) && isvowel(words[a][words[a].size()-1]) ;
            } 
            else{
                int c = (b != 0) ? prefix[b-1] : 0;
                ans[i] = prefix[a] - c;
            }
        }

        return ans;
    }
};