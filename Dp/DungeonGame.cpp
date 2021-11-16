class Solution {
public:
    int dp[200][200];
    int solve(vector<vector<int>> &grid, int n, int m, int i, int j) 
    {
        if(i >= n || j >= m) 
            return INT_MAX;
        if(i == n-1 && j == m-1) 
            return grid[i][j] <= 0 ? abs(grid[i][j]) + 1 : 1;
        if (dp[i][j] != -1) 
            return dp[i][j];
        int right = solve(grid, n, m, i, j+1);
        int down = solve(grid, n, m, i+1, j);
        int ans = min(right, down) - grid[i][j];
        return dp[i][j] = ans <=0 ? 1 : ans;
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon) 
    {
        if(dungeon.size() == 0) 
            return 0;
        memset(dp, -1, sizeof(dp));
        return solve(dungeon, dungeon.size(), dungeon[0].size(), 0, 0);
    }
};