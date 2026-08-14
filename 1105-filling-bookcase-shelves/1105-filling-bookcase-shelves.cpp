class Solution {
public:

    int solve(int i, int n, vector<vector<int>>& books,
              int shelfWidth, vector<int>& dp) {

        // No books remaining
        if (i == n)
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        int width = 0;
        int height = 0;

        int ans = INT_MAX;

        // Try putting books i...j on the current shelf
        for (int j = i; j < n; j++) {

            width += books[j][0];

            // Current shelf cannot contain more books
            if (width > shelfWidth)
                break;

            height = max(height, books[j][1]);

            // Current shelf height + remaining shelves
            ans = min(
                ans,
                height + solve(j + 1, n, books, shelfWidth, dp)
            );
        }

        return dp[i] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books,
                         int shelfWidth) {

        int n = books.size();

        vector<int> dp(n, -1);

        return solve(0, n, books, shelfWidth, dp);
    }
};