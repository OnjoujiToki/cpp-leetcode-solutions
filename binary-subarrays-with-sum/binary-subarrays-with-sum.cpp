class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        m[0] = 1;
        int res = 0, prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            if (m.find(prefix - goal) != m.end()) {
                res += m[prefix - goal];
            }
            m[prefix]++;
        }
        return res;
    }
};