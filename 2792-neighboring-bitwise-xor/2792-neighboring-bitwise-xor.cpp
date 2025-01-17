class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xori = 0;
        for(auto it : derived){
            xori ^= it; 
        }
        if(xori == 0) return true;
        return false;
    }
};