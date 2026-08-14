class Solution {
public:
    int solve(int i, int n, string &s, vector<int>& dp) {

        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        vector<int> freq(26, 0);

        for (int j = i; j < n; j++) {

            // Duplicate character
            if (freq[s[j] - 'a'] != 0)
                break;

            freq[s[j] - 'a']++;

            ans = min(ans,
                      1 + solve(j + 1, n, s, dp));
        }

        return dp[i] = ans;
    }

    int partitionString(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, n, s, dp);
    }
};