// Last updated: 12/8/2025, 11:26:55 PM
class Solution {
public:
    int scoreOfParentheses(string s) {
        int bal = 0;
        int score = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') bal++;
            else {
                bal--;
                if (s[i - 1] == '(')
                    score += 1 * pow(2, bal);
            }
        }
        return score;
    }
};