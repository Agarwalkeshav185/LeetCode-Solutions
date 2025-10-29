class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int ans=0;
        for(auto it : operations){
            if(it[0]=='X'){
                if(it[it.length()-1]=='-'){
                    ans--;
                }
                else if(it[it.length()-1]=='+'){
                    ans++;
                }
            }
            else if(it[0]=='-'){
                ans--;
            }
            else if(it[0]=='+'){
                ans++;
            }
        }
        return ans;
    }
};