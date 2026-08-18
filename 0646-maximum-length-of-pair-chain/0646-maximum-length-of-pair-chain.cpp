class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        int ans = 0;
        int prev = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (pairs[i][0] > prev) {
                ans++;
                prev = pairs[i][1];
            }
        }

        return ans;
    }
};