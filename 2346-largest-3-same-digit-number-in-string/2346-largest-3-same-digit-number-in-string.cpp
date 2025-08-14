class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string ans="";

        int i=0, j=0;
        unordered_map<char, int> count;
        while(j<n){
            count[num[j]]++;
            while(i<j && count.size()>1){
                count[num[i]]--;
                if(count[num[i]]==0) count.erase(num[i]);
                i++;
            }
            if(count.size() == 1 && count[num[j]]==3){
                if(ans.empty() || ans[0] < num[j]){
                    ans = "";
                    ans.push_back(num[j]);
                    ans.push_back(num[j]);
                    ans.push_back(num[j]);
                }
            }
            j++;
        }
        return ans;


    }
};