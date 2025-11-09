class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.length() != 1){
            int m = s.length()-1;
            if(s[m]=='1'){
                while(m>=0 && s[m]=='1'){
                    s[m]='0';
                    m--;
                }
                if(m>=0) s[m]='1';
                else if(m<0) s = '1' + s;
            }
            else if(s[m]=='0'){
                s.pop_back();
            }
            ans++;
        }
        return ans;
    }
};