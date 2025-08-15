class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1 || n == 4 || n==16 || n==64 || n==256 || n==1024 || n==4096 || n==16384 || n==65536 || n==262144 || n==1048576 || n==4194304 || n==16777216 || n==67108864 || n==268435456 || n==1073741824) return true;
        return false;
    }
};