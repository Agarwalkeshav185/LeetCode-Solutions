class Solution {
public:
    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        stack<int> stk;
        vector<int> arr(n,n);

        for(int i=n-1; i>=0 ; i--){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                arr[i] = stk.top();
            }
            stk.push(i);
        }
        return arr;
    }

    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        stack<int> stk;
        vector<int> arr(n, -1);

        for(int i=0;i<n; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(!stk.empty()){
                arr[i] = stk.top();
            }

            stk.push(i);
        }
        return arr;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int ans = 0;

        vector<int> nxts = nse(heights);
        vector<int> prevs = pse(heights);
        for(int i= 0; i<n; i++){
            int left = i - prevs[i];
            int right = nxts[i] - i;
            ans = max(ans, heights[i] * (nxts[i]-prevs[i]-1));
        }

        return ans;
    }
};