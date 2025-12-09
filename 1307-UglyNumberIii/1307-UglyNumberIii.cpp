// Last updated: 12/8/2025, 11:26:18 PM
class Solution {
public:
    long long gcd(long long x, long long y) {
        while (y) {
            long long t = x % y;
            x = y;
            y = t;
        }
        return x;
    }

    long long lcm(long long x, long long y) {
        return x * y / gcd(x, y);
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);
        long long low = 1, high = (long long) min({a, b, c}) * n;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long cnt = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
            if (cnt < n) low = mid + 1;
            else high = mid;
        }
        return (int)low;
    }
};