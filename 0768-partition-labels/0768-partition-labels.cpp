class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, int> countWhole;
        unordered_map<char, int> countPart;
        int cnt=0;
        for(int i=0;i<n; i++){
            countWhole[s[i]]++;
        }
        int j=0;

        vector<int> ans;
        for(int i=0;i<n; i++){
            countPart[s[i]]++;
            bool flag = true;
            for(auto it : countPart){
                if(it.second != countWhole[it.first]){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(i-j+1);
                j = i+1;
            }
        }
        return ans;
    }
};