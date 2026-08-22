class Solution {
public:

    const int MOD = 1e9 + 7;

    int dp[500][51][2][2];

    vector<int> lps;

    string evil;

    // Build KMP LPS array
    void buildLPS() {

        int m = evil.size();

        lps.assign(m, 0);

        int j = 0;

        for (int i = 1; i < m; i++) {

            while (j > 0 && evil[i] != evil[j])
                j = lps[j - 1];

            if (evil[i] == evil[j])
                j++;

            lps[i] = j;
        }
    }

    // KMP transition
    int getNext(int matched, char c) {

        while (matched > 0 && evil[matched] != c)
            matched = lps[matched - 1];

        if (evil[matched] == c)
            matched++;

        return matched;
    }

    int solve(int i,
              int matched,
              int tight1,
              int tight2,
              string &s1,
              string &s2) {

        // evil has appeared
        if (matched == evil.size())
            return 0;

        // Constructed a complete valid string
        if (i == s1.size())
            return 1;

        if (dp[i][matched][tight1][tight2] != -1)
            return dp[i][matched][tight1][tight2];

        char lo = tight1 ? s1[i] : 'a';
        char hi = tight2 ? s2[i] : 'z';

        long long ans = 0;

        for (char c = lo; c <= hi; c++) {

            int newMatched = getNext(matched, c);

            int newTight1 =
                tight1 && (c == s1[i]);

            int newTight2 =
                tight2 && (c == s2[i]);

            ans += solve(i + 1,
                         newMatched,
                         newTight1,
                         newTight2,
                         s1,
                         s2);

            ans %= MOD;
        }

        return dp[i][matched][tight1][tight2] = ans;
    }

    int findGoodStrings(int n,
                        string s1,
                        string s2,
                        string evil) {

        this->evil = evil;

        buildLPS();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 1, 1, s1, s2);
    }
};