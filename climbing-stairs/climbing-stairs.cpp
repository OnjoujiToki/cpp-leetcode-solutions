class Solution {
public:
    int climbStairs(int n) {
        long long dp[2]{1,2};
        if (n == 1) return 1;
        for (int i = 3; i <=n;i = i+2) {
            int cur = dp[0] + dp[1];
            dp[0] = cur;
            dp[1] = dp[1] + cur; 
        }
        if (n%2) return dp[0];
        return dp[1];
    }
};