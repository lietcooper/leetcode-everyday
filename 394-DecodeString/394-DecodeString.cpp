// Last updated: 12/8/2025, 11:28:57 PM
class Solution {
public:
    // int i = 0;
    // string decodeString(const string& s) {
    //     string ans = "";
    //     while (i < s.size() && s[i] != ']') {
    //         // append leading characters
    //         if (!isdigit(s[i])) {
    //             ans += s[i];
    //             i++;
    //         } else {
    //             int k = 0;
    //             while (i < s.length() && isdigit(s[i])) {
    //                 k = k * 10 + s[i] - '0';
    //                 i++;
    //             }
    //             i++;  // skip [
    //             string next = decodeString(s);
    //             i++;  // skip ]
    //             while (k--) ans += next;
    //         }
    //     }
    //     return ans;
    // }

    string decodeString(const string& s) {
        stack<int> numbers;
        stack<string> strs;
        string current = "";
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + c - '0';
            } else if (c == '[') {
                numbers.push(k);
                k = 0;
                strs.push(current);
                current = "";
            } else if (c == ']') {
                string decoded = strs.top();
                strs.pop();
                int times = numbers.top();
                numbers.pop();
                while (times--) decoded = decoded + current;
                current = decoded;
            } else {
                current += c;
            }
        }
        return current;
    }
};