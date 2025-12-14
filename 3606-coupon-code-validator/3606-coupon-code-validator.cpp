class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> count;
        for(int i=0;i<n; i++){
            bool flag = false;
            for(int j=0;j<code[i].size(); j++){
                if( ('A' <= code[i][j] && code[i][j] <='Z') || ('a' <= code[i][j] && code[i][j] <='z') || ('0' <= code[i][j] && code[i][j] <= '9') || (code[i][j] == '_')){
                    continue;
                }
                else {
                    flag = true;
                    break;
                }
            }
            if(!flag){
                if(isActive[i] && ((businessLine[i] == "electronics") || (businessLine[i] == "restaurant") || (businessLine[i] == "grocery") || (businessLine[i] == "pharmacy"))){
                    if(!code[i].empty()) count.push_back({businessLine[i], code[i]});
                }
            }
        }
        sort(count.begin(), count.end());
        vector<string> ans;
        for(int i=0;i<count.size(); i++){
            ans.push_back(count[i].second);
        }
        return ans;
    }
};