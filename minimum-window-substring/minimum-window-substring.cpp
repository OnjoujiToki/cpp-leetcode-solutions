class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int>cur;
        unordered_map<int, int>dic;
        int minLen = INT_MAX;
        for (auto& x: t) {
            cur[x] = 0;
            dic[x] ++;
        }
        int l = 0;
        int r = 0;
        int match = 0;
        int start = 0;
        for (int r = 0; r < s.size(); r++) {
            if (cur.find(s[r]) != cur.end()) {
                cur[s[r]]++;
                if (cur[s[r]] == dic[s[r]]) match++;
            }
            while(l <= r && match == dic.size()) {
                if (minLen > r - l +1){
                    start = l;
                    minLen = r - l +1;
                }
                if (cur.find(s[l]) != cur.end()) {
                    if (cur[s[l]]-1< dic[s[l]]) match--;
                    cur[s[l]]--;
                }
                l++;
            }
        }
        
        string res;
        return minLen == INT_MAX?res: s.substr(start, minLen);
    }
};