// Last updated: 12/8/2025, 11:26:58 PM
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_l = process(s);
        int t_l = process(t);
        if (s_l != t_l) return false;
        for (int i = 0; i < s_l; i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
private:
    int process(string& source) {
        int slow = 0;
        for (int fast = 0; fast < source.length(); fast++) {
            if (source[fast] != '#') {
                source[slow++] = source[fast];
            } else {
                if (slow > 0) slow--;
            }
        }
        return slow;
    }
};