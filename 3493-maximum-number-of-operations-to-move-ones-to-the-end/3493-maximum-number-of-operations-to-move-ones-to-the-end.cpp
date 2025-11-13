class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int cnt = 0;
        bool flag = 0;
        int ans=0;
        for(int i=0; i<n; i++){

            if(s[i] == '1'){
                flag = 1;
                cnt++;
            }
            else {
                flag = 0;
                while(i<n && s[i+1] =='0') i++;
            }
            if(flag == 0 ) ans += cnt;
        }
        return ans;
    }
};