class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxCount = -1;
        vector<vector<int>>dp (2, vector<int>(n,0));
        for (int i = 0 ; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if (i==0|| j== 0) {
                    if (matrix[i][j] == '1') dp[i&1][j] = 1;
                    else dp[i&1][j] = 0;
                }else {
                    if (matrix[i][j] == '1') dp[i&1][j] = min(dp[i-1&1][j-1], min(dp[i-1&1][j], dp[i&1][j-1]))+1;
                    else dp[i&1][j] = 0;
                    
                }
                maxCount= max(dp[i&1][j], maxCount);
                
            }
         }
         return maxCount*maxCount; 
    }
};