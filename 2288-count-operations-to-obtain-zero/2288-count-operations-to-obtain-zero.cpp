class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(true){
            if( num1 == 0 || num2 == 0){
                return ans;
            }
            else if (num1 >= num2){
                num1 -= num2;
            }
            else num2 -= num1;
            ans++;
        }
        return ans;
    }
};