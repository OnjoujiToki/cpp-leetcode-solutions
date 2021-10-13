class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return s
        
        answer = (0, 0) # length and start tuple will compare first element as default
        for mid in range(len(s)):
            answer = max(answer, self.getString(s, mid, mid))
            answer = max(answer, self.getString(s, mid, mid + 1))
        
        return s[answer[1]: answer[0] + answer[1]]  

    def getString(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1, left + 1
