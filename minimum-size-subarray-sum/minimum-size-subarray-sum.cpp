class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0 ) return 0;
        int curSum = 0;
        int l = 0, r = 0;
        int minLength = INT_MAX;
        while(r < nums.size()) {
            curSum += nums[r];
            while (curSum>= target) {
                minLength = min(r-l+1, minLength);
                curSum -=nums[l];
                l++;
            }
            r++; // care about its position
        }
        return minLength == INT_MAX ? 0 : minLength;
        
    }
};