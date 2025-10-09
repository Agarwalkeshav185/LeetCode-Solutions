class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> count = { {1,"I"}, {4,"IV"}, {5,"V"},
                        {9,"IX"}, {10,"X"}, {40,"XL"},
                        {50,"L"}, {90, "XC"}, {100,"C"}, 
                        {400, "CD"}, {500, "D"}, {900, "CM"}, 
                        {1000, "M"}};
        
        int n = num;
        string ans="";
        int i = count.size()-1;
        while(n>0 && i>=0){
            if(num >= count[i].first){
                ans += count[i].second;
                num -= count[i].first;
            }
            else i--;
        }
        return ans;
    }
};