class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            string s = "";
            string t = "";
            while(i < n && version1[i] == '0') i++;
            while(j < n && version2[j] == '0') j++;
            while(i < n && version1[i] != '.'){
                s += version1[i];
                i++;
            }
            while(j < m && version2[j] != '.'){
                t += version2[j];
                j++;
            }
            int num1 = 0, num2 = 0;
            if(s.length() > 0) num1 = stoi(s);
            if(t.length() > 0) num2 = stoi(t);
            if(num1 < num2) {
                return -1;
            }
            if(num1 > num2) return 1;
            i++;
            j++;
        }
        while(i < n){
            if(version1[i] != '0' && version1[i] != '.') return 1;
            i++;
        }
        while(j < m){
            if(version2[j] != '0' && version2[j] != '.') return -1;
            j++;
        }
        return 0;
    }
};