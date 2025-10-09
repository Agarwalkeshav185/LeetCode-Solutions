class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> count;
        set<int> dry;
        vector<int> ans(n,1);
        for(int i=0;i<n; i++){
            if(rains[i]==0){
                dry.insert(i);
            }
            else{
                if(count.find(rains[i]) != count.end()){
                    auto ind = dry.upper_bound(count[rains[i]]);
                    if(ind == dry.end()) return {};
                    ans[*ind] = rains[i];
                    dry.erase(ind);
                }
                ans[i] = -1;
                count[rains[i]] = i;
            }
        }
        return ans;
    }
};