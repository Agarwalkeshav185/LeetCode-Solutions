class Solution {
public:
    int binary(vector<int>& potions, int spell, long long success){
        int n = potions.size();
        if(potions[n-1]*1LL*spell < success) return 0;
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(success <= spell*1LL*potions[mid]){
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return n-start;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();

        vector<int> ans;
        for(int i=0;i<n; i++){
            int value = binary(potions, spells[i], success);
            ans.push_back(value);
        }
        return ans;
    }
};