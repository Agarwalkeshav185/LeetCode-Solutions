class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> ans;
        ans.push_back(words[0]);
        for(auto it : words){
            string temp = it;
            string temp2 = ans.back();
            sort(temp2.begin(), temp2.end());
            sort(temp.begin(), temp.end());
            if(temp != temp2){
                ans.push_back(it);
            }
        }
        return ans;
    }
};