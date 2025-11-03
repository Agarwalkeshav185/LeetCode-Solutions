class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long ans = 0;
        long long start=1, end = 1e14;
        while(start <= end){
            long long mid = start + (end-start)/2;
            long long d0 = mid - mid/lcm(r[0],r[1]);
            long long d1 = mid - mid/ r[0];
            long long d2 = mid - mid/r[1];
            if(d[0]+d[1] <= d0 && d[0] <= d1 && d[1]<= d2 ){
                end = mid-1;
            }
            else start = mid+1;;
        } 
        return start;
    }
};