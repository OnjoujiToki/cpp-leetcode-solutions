class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (2,vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i==0 || j==0) {
                    dp[i&1][j] = 1;
                } else {
                    dp[i&1][j] = dp[i-1&1][j] + dp[i&1][j-1];
                }
            }
        }
        return max(dp[0][n-1], dp[1][n-1]);
    }
};