class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(true){
            if(num==0){
                return ans;
            }
            else if(num%2){
                num -= 1;
            }
            else num = num>>1;
            ans++;
        }
        return ans;
    }
};