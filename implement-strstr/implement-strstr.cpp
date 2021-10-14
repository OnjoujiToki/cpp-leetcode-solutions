class Solution {
public:
    int strStr(string source, string target) { 
        if (target.empty()) return 0;
        if (source.empty()) return -1;
        int m = target.size();
        int n = source.size();
        // a * 31 ^ m;
        int power = 1;
        // calculate 31^m
        for (int i = 0; i < m; i++) {
            power = (power * 31) % BASE;
        }
        int targetCode = 0;
        for (int i = 0; i < m; i++) {
            targetCode = (targetCode * 31 + target[i]) % BASE;
        }
        int hashCode = 0;
        for (int i = 0; i < n; i++) {
            // abc + d
            hashCode = (hashCode * 31 + source[i]) % BASE;
            if (i < m - 1) {
                continue;
            }

            // cur at d, so minus m...
            // abcd - a
            if (i >= m) {
                hashCode = (hashCode - source[i-m] * power) % BASE;
                if (hashCode < 0) {
                    hashCode += BASE;
                }
            }
            if (hashCode == targetCode) {
                // double check 
                if (source.substr(i - m + 1, m ) == target) return i - m + 1;
            }
        }
        return -1;
    }
private:
    const int BASE = 1000000;
};