class Solution {
public:
    int largestPerimeter(vector<int>& num) {
        int n=num.size();
        int ma=0;
        sort(num.begin(),num.end());
        for(int i=0; i<n-2; i++){
            int j=i+1;
            int k=i+2;
            int s = (num[i]+num[j]+num[k]);
            if(((num[i]+num[j])>num[k]) && ((num[j]+num[k])>num[i]) && ((num[i]+num[k])>num[j])){
                ma = max(s,ma);
            }
        }
        return ma;
    }
};