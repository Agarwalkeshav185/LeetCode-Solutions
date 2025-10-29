class Solution {
public:
    int smallestNumber(int n) {
        int len = log2(n) + 1;
        return (1 << len)-1;
    }
};