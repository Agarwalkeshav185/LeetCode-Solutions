class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int i=0 , j=n-1;
        int final = 0;
        while(i<j){
            int area = min(height[i],height[j])*(j-i);
            final = max(final, area);
            if(height[j]>height[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return final;
    }
};