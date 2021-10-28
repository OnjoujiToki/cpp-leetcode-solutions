class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        int m = triangle.size();
        int n = triangle.back().size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = triangle[0][0];
        // dp[i][j] = dp[i-1][j-1] + dp[i-1][j] 
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j];
                if (j == 0) dp[i][j] += dp[i-1][j];
                else if (j == i) dp[i][j] += dp[i-1][j-1];
                else dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        
        return *min_element(dp.back().begin(), dp.back().end());
    }
};