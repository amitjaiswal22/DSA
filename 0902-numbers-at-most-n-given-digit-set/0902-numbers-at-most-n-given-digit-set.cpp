class Solution {
public:
    int dp[10][2][2];
    vector<int> d;

    int solve(int i, int tight, int started, string &s) {
        if (i == s.size()) {
            return started;   // positive number only
        }
        if (dp[i][tight][started] != -1)
            return dp[i][tight][started];
        int limit = tight ? s[i] - '0' : 9;
        long long ans = 0;
        // Option: don't start yet
        if (!started) {
            ans += solve(i + 1, tight && (0 == limit),
                         0, s);
        }
        for (int x : d) {

            if (x > limit)
                break;

            int newTight = tight && (x == s[i] - '0');

            ans += solve(i + 1,
                         newTight,
                         1,
                         s);
        }

        return dp[i][tight][started] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        d.clear();
        for (auto &x : digits)
            d.push_back(x[0] - '0');
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, s);
    }
};