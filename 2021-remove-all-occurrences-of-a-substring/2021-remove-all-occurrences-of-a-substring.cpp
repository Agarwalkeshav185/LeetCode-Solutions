class Solution {
public:
    string removeOccurrences(string s, string part) {
        int slen=s.length();
        int partlen=part.length();
        int index=0;
        while(s.length()>=0 && s.find(part) < s.length()){
            index= s.find(part);
            s.erase(index,partlen);
        }
        return s;
    }
};