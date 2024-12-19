class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack <int> st;
        st.push(arr[0]);
        for(int i=1; i<n; i++){
            if(arr[i] > st.top()){
                st.push(arr[i]);
            }
            else{
                int maxi = st.top();
                while(!st.empty() && st.top() > arr[i]) st.pop();
                st.push(maxi);
            }
        }
        return st.size();
    }
};