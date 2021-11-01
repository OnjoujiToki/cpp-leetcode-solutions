class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = 0;
        int n = matrix.size();
        if (n == 0) return res;
        if (n == 1) return matrix[0][0];
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int left = INT_MAX;
                int right = INT_MAX;
                if (j > 0) left = min(dp[i-1][j-1], dp[i-1][j]);
                if (j < n -1) right = min(dp[i-1][j], dp[i-1][j+1]);
                dp[i][j] = min(left, right)+ matrix[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};