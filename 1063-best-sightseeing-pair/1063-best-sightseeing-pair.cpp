class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        if(n==2) return values[0]+values[1]-1;
        vector<int> maxi(n,0);
        int maxii=0;
        for(int i=0;i<n; i++){
            maxi[i] = maxii;
            maxii = max(maxii, values[i]+i);
        }
        int ans=0;
        for(int i=n-1; i>0; i--){
            ans = max(maxi[i]+values[i]-i, ans);
        }
        return ans;
    }
};