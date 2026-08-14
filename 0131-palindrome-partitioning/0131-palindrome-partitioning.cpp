class Solution {
public:

    int dp[2001][2001];

    bool check(int i, int j, string &s) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int l = i;
        int r = j;

        while (l < r) {
            if (s[l] != s[r])
                return dp[i][j] = 0;

            l++;
            r--;
        }

        return dp[i][j] = 1;
    }

    vector<vector<string>> ans;

    void solve(int i, int n, string &s, vector<string>& temp) {

        if (i >= n) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < n; j++) {

            if (check(i, j, s)) {

                temp.push_back(s.substr(i, j - i + 1));

                solve(j + 1, n, s, temp);

                temp.pop_back();   // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {

        memset(dp, -1, sizeof(dp));

        int n = s.size();

        vector<string> temp;

        solve(0, n, s, temp);

        return ans;
    }
};