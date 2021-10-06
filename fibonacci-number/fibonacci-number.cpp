class Solution {
public:
    int fib(int n) {
        int dp[2] = {0,1};
        if (n == 0) return dp[0];
        if (n == 1) return dp[1];
        for (int i = 2; i <=n;i = i +2){
            int curFirst = dp[0] + dp[1];
            int curSecond = dp[1] +curFirst;
            dp[0]= curFirst;
            dp[1] = curSecond;
        }
        if (n%2 == 0) return dp[0];
        return dp[1];
    }
};