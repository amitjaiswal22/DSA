class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int n = ob.size();
        int m = ob[0].size();

        vector<long long> prev(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<long long> curr(m + 1, 0);

            for (int j = m - 1; j >= 0; j--) {

                if (ob[i][j] == 1) {
                    curr[j] = 0;
                }
                else if (i == n - 1 && j == m - 1) {
                    curr[j] = 1;
                }
                else {
                    long long down = prev[j];
                    long long right = curr[j + 1];

                    curr[j] = down + right;
                }
            }

            prev = curr;
        }

        return prev[0];
    }
};