class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> count(26,0);

        for(int i=0;i<n; i++){
            count[s[i]-'a']++;
        }

        // for(int i=0;i<26; i++){
        //     cout<<char(i+'a') <<" "<<count[i]<<endl;
        // }
        int cnt=0;
        for(int i=0;i<26; i++){
            if(count[i] != 0){
                int a = count[i];
                while(a>=3){
                    a = a/3 + a%3;
                }
                count[i] = a;
            }
            cout<<count[i]<<" ";
            cnt += count[i];
        }
        return cnt;
        
    }
};