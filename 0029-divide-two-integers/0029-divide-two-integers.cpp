class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int ans = 0;
        bool neg = false;
        if(divisor <0 && dividend <0) neg = false;
        else if(divisor <0 || dividend <0) neg = true;

        long long divid = abs((long long)dividend);
        long long divi = abs((long long)divisor);
        if(divid  == INT_MAX && neg && divi == 1) return -divid;
        else if(divid >INT_MAX && neg && divi == 1) return INT_MIN;
        else if(divid >= INT_MAX && divi == 1) return INT_MAX;

        while(divid >= divi){
            ans++;
            divid -= divi;
        }
        if(ans >=INT_MAX && neg) return INT_MIN;
        else if(ans >= INT_MAX) return INT_MAX;

        if(neg) return -ans;
        return ans;
    }
};