class Solution {
public:
    int dp[20][2][1024][2];

    int solve(int i, int tight, int mask, int started, string &s) {
        // One valid number formed
        if (i == s.size())
            return 1;
        if (dp[i][tight][mask][started] != -1)
            return dp[i][tight][mask][started];
        int limit = tight ? s[i] - '0' : 9;
        int ans = 0;
        for (int d = 0; d <= limit; d++) {
            int newTight = tight && (d == s[i] - '0');// Leading zero
            if (!started && d == 0) {
ans += solve(i + 1,newTight,mask,0, s);
            }
            else {
// Digit already used
                if (mask & (1 << d))
                    continue;
ans += solve(i + 1,newTight, mask | (1 << d),1,s);
            }
        }
        return dp[i][tight][mask][started] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        int unique = solve(0, 1, 0, 0, s);
        // Remove 0 because problem asks [1,n]
        unique--;
        return n - unique;
    }
};