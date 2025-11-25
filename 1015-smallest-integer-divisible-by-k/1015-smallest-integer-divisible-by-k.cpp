class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long remainder = 1;
        int length = 1;
        unordered_map<long long , bool > count;
        while(remainder%k !=0){
            long long N = remainder*10 +1;
            remainder = N%k;
            length++;
            if(count[remainder]){
                return -1;
            }
            else {
                count[remainder] = true;
            }
        }
        return length;
    }
};