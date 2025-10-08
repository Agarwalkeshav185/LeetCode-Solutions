class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> stk;
        for(int i=0; i<n; i++){
            if(!stk.empty() && s[stk.top()]=='(' && s[i]==')'){
                stk.pop();
            }
            else{
                stk.push(i);
            }
        }

        int ans = 0;
        int prev = n;
        while (!stk.empty()) {
            ans = max(ans, prev - stk.top() - 1);
            prev = stk.top();
            stk.pop();
        }
        ans = max(ans, prev);
        return ans;

    }
};