class Solution {
public:
    long long solve(int i, int j, int n, int m,
                    vector<vector<int>>& grid,
                    vector<vector<long long>>& dp) {

        if (i == n)
            return 0;

        if (dp[i][j] != LLONG_MAX)
            return dp[i][j];

        long long ans = LLONG_MAX;

        for (int k = 0; k < m; k++) {

            if (k == j)
                continue;

            ans = min(ans,
                      (long long)grid[i][k] +
                      solve(i + 1, k, n, m, grid, dp));
        }

        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> dp(
            n, vector<long long>(m, LLONG_MAX)
        );

        long long ans = LLONG_MAX;

        // First row: no previous column
        for (int j = 0; j < m; j++) {
            ans = min(ans, (long long)grid[0][j] +
                            solve(1, j, n, m, grid, dp));
        }

        return (int)ans;
    }
};