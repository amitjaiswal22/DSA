class Solution {
public:
    int mod = 1e9 + 7;

    int dp[200][2][11];

    string subtractOne(string s) {

        int i = s.size() - 1;

        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }

        if (i >= 0)
            s[i]--;

        int pos = 0;

        while (pos + 1 < s.size() && s[pos] == '0')
            pos++;

        return s.substr(pos);
    }

    int solve(int i, int t, int prev, string &s) {

        if (i == s.size())
            return 1;

        if (dp[i][t][prev] != -1)
            return dp[i][t][prev];

        int l = t ? s[i] - '0' : 9;

        long long ans = 0;

        for (int d = 0; d <= l; d++) {

            int newt = t && (d == s[i] - '0');

            // Still haven't started the number
            if (prev == 10 && d == 0) {
                ans += solve(i + 1, newt, 10, s);
            }
            // Number already started
            else if (prev == 10 || abs(d - prev) == 1) {
                ans += solve(i + 1, newt, d, s);
            }

            ans %= mod;
        }

        return dp[i][t][prev] = ans;
    }

    int countSteppingNumbers(string low, string high) {

        memset(dp, -1, sizeof(dp));

        // prev = 10 means no digit has been started
        int right = solve(0, 1, 10, high);

        string a = subtractOne(low);

        memset(dp, -1, sizeof(dp));

        int left = solve(0, 1, 10, a);

        return (right - left + mod) % mod;
    }
};