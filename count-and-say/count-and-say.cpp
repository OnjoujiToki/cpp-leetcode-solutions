class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "1";
        for (int i = 1; i < n; i++) {
            string ns;
            for (int j = 0;j < s.size();) {
                int u = j;
                while (u<s.size() && s[u] == s[j]) u++;
                ns += to_string(u-j); // counted number
                ns += s[j];
                j = u; // continue loop
            }
            s = ns;
        }
        return s;
    }
};