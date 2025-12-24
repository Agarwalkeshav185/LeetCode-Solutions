class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long sum = 0;
        sort(capacity.rbegin(), capacity.rend());
        for(auto it : apple){
            sum += it;
        }
        int ans = 0;
        int count = 0;
        for(auto it : capacity){
            if(ans >= sum ) return count;
            else {
                count++;
                ans += it;
            }
        }
        return count;
    }
};