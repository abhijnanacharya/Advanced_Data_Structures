class Solution {
public:
    double helper(int N, int K, int r, int c, vector<vector<vector<double>>> & dp){
        if(r < 0 || c < 0 || r >= N || c >= N) return 0;
        if(K == 0) return 1;
        if(dp[r][c][K] != -1) return dp[r][c][K];
        double sum = helper(N, K - 1, r - 2, c - 1, dp) +
                     helper(N, K - 1, r - 1, c - 2, dp) +
                     helper(N, K - 1, r + 1, c - 2, dp) +
                     helper(N, K - 1, r + 2, c - 1, dp) +
                     helper(N, K - 1, r - 2, c + 1, dp) +
                     helper(N, K - 1, r - 1, c + 2, dp) +
                     helper(N, K - 1, r + 1, c + 2, dp) +
                     helper(N, K - 1, r + 2, c + 1, dp);
        sum = sum / 8;
        dp[r][c][K] = sum;
        return dp[r][c][K];
    
    }
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N + 1, vector<vector<double>> (N + 1, vector<double>(K + 1, -1)));
        return helper(N, K, r, c, dp);
    }
};