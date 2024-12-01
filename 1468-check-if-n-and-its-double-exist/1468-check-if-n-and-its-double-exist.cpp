class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<double , int> count;
        int n = arr.size();

        for(int i=0;i<n; i++){
            count[arr[i]]++;
        }

        for(int i=0;i<n; i++){
            if(arr[i]==0 && count[arr[i]]>=2) return true; 
            if(arr[i] !=0 && (count.find(arr[i]*2) != count.end() || count.find(arr[i]/2.0) != count.end())) return true;
        }
        return false;

    }
};