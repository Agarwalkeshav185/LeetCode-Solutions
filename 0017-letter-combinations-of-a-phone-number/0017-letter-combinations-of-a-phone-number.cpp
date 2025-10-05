class Solution {
public:
    void solve(string& digits, vector<vector<char>>& count, int i, vector<string>& ans, string& s){
        if(i >= digits.size()) {
            ans.push_back(s);
            return;
        }
        
        for(int j=0; j < count[digits[i]-'2'].size(); j++){
            s.push_back(count[digits[i]-'2'][j]);
            solve(digits, count, i+1, ans, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<vector<char>> count = { {'a','b','c'}, {'d','e','f'}, 
                                    {'g','h','i'}, {'j','k','l'}, 
                                    {'m','n','o'}, {'p','q','r','s'}, 
                                    {'t','u','v'}, {'w','x','y','z'}
                                    };
        string s = "";
        vector<string> ans;
        solve(digits, count, 0, ans, s);
        return ans;
        
    }
};