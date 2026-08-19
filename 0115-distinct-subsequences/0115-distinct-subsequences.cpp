class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<long long> prev(m + 1, 0);
        prev[m] = 1;

        for(int i = n - 1; i >= 0; i--) {

            vector<long long> curr(m + 1, 0);
            curr[m] = 1;

            for(int j = m - 1; j >= 0; j--) {

                if(s[i] == t[j]) {
                    curr[j] = min(
                        (long long)INT_MAX,
                        prev[j + 1] + prev[j]
                    );
                }
                else {
                    curr[j] = prev[j];
                }
            }

            prev = curr;
        }

        return (int)prev[0];
    }
};