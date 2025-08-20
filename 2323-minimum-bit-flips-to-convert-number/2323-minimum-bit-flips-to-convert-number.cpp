class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long int num = start^goal;
        int cnt=0;
        while(num){
            if(num&1) cnt++;
            num = num>>1;
        }
        return cnt;
    }
};