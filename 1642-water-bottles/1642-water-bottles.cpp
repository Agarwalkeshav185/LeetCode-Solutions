class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full = 0;
        int ans = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            ans += full;
            full = empty/numExchange;
            empty = empty%numExchange + full;
        }
        ans += full;
        return ans;
    }
};