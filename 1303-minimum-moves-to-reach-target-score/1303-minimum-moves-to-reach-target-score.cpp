class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while(target != 1){
            if(target == 1){
                return steps;
            }
            else if(maxDoubles>0 && target%2==0){
                maxDoubles--;
                target /=2;
            }
            else if(maxDoubles ==0 ){
                return target + steps-1;
            }
            else {
                target -= 1;
            }
            steps++;
        }
        return steps;
    }
};