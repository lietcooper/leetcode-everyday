// Last updated: 12/8/2025, 11:28:53 PM
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // NG: leading zero / number out of range e.g. "s55n"
        /**
            iterate abbr:
                parse integer:
                    if leading zero: return false
                    else: move index in word this amount of steps forward

                    if integer added to index out of word range: return false
                else compare each character:
                    if not same: return false

            return true
        */
        size_t i = 0;
        size_t j = 0;
        while (i < word.length() && j < abbr.length()) {
            if (!isdigit(abbr[j])) {
                if (word[i] == abbr[j]) {
                    i++;
                    j++;
                }
                else return false;
            } else {
                if (abbr[j] == '0') return false;
                unsigned int num = 0;
                while (j < abbr.length() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num;
                if (i > word.length()) return false;   
            }
        }
        return i == word.length() && j == abbr.length();
    }
};