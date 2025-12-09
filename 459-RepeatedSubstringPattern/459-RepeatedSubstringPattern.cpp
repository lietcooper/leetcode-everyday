// Last updated: 12/8/2025, 11:28:41 PM
class Solution {
public:
    // bool repeatedSubstringPattern(string s) {
    //     int n = s.length();
    //     for (int i = 1; i <= n / 2; ++i) {
    //         if (n % i == 0) {
    //             string pattern = "";
    //             for (int j = 0; j < n / i; ++j) {
    //                 pattern += s.substr(0, i);
    //             }
    //             if (s == pattern) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // bool repeatedSubstringPattern(string s) {
    //     string t = s + s;
    //     if (t.substr(1, t.size() - 2).find(s) != std::string::npos) return true;
    //     return false;
    // }

    void getNext (int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1;i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if(s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};