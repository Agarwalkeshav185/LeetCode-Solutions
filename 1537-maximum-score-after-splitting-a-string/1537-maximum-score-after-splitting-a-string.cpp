class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int oneCount = 0;
        for (char c : s) {
            if (c == '1') oneCount++;
        }

        int maxScore = 0;
        int leftZeroCount = 0, rightOneCount = oneCount;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') leftZeroCount++;
            if (s[i] == '1') rightOneCount--;
            int score = leftZeroCount + rightOneCount;
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
