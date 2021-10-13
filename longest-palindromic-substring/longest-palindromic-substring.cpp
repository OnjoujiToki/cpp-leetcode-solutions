class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        int length = s.size();
        int maxLength = INT_MIN;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {  
            checkString(s, i, i, maxLength, start);
            checkString(s, i, i + 1, maxLength, start);
        }
        return maxLength == INT_MIN? "" : s.substr(start, maxLength);
    }
private: 
        void checkString(string s, int left, int right, int& maxLength, int& start) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > maxLength) {
                maxLength = right - left - 1;
                start = left + 1; // left左移过一次
            }
        }

};