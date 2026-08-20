class Solution {
public:
    int solve(int i, int row, int n, vector<int>& arr, vector<int>& dp) {

        if (row == n - 1)
            return arr[i];

        if (dp[i] != INT_MAX)
            return dp[i];

        int left = solve(i + row + 1, row + 1, n, arr, dp);
        int right = solve(i + row + 2, row + 1, n, arr, dp);

        return dp[i] = arr[i] + min(left, right);
    }

    int minimumTotal(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> arr;

        for (auto &row : grid)
            for (int x : row)
                arr.push_back(x);

        vector<int> dp(arr.size(), INT_MAX);

        return solve(0, 0, n, arr, dp);
    }
};