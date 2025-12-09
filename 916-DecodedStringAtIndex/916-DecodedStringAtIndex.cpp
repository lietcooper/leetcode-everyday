// Last updated: 12/8/2025, 11:26:48 PM
class Solution {
public:
    // string decodeAtIndex(string s, int k) {
    //     string res = "";
    //     int i = 0;
    //     while (res.size() < k) {
    //         if (isdigit(s[i])) {
    //             int j = s[i] - '0';
    //             string temp = res;
    //             while (--j) {
    //                 res += temp;
    //             }
    //         } else {
    //             res += s[i];
    //         }
    //         i++;
    //     }
        
    //     return string(1, res[k - 1]);
    // }

    string decodeAtIndex(string s, int k) {
        long sz = 0;
        int n = s.size();
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                sz *= s[i] - '0';
            } else {
                sz++;
            }
        }

        /** 
            apple2android3    size = 54,  k = 45
            appleappleandroidappleappleandroidappleappleandroid

            appleappleandroid  sz = 17
            k = 11

            appleapplea  sz = 11
            k = 0
        */
        for (int i = n - 1; i >= 0; --i) {
            k %= sz;
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            if (isdigit(s[i])) {
                sz /= s[i] - '0';   
            } else {
                sz--;
            }
        }
        return "";
    }
};