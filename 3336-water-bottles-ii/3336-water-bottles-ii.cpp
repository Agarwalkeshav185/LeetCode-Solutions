class Solution {
public:
    int maxBottlesDrunk(int full, int change) {
        int ans=full;
        int emp = full;
        full=0;
        while( (emp+full) >= change){
            emp -= change;
            change++;
            full++;
            if(full == change){ 
                emp +=full;
                ans += full;
                full=0;
            }
        }
        if(full!=0){
            ans+=full;
        }
        return ans;

    }
};