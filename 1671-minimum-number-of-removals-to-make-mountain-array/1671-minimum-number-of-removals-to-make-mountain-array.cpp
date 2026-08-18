class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);
        vector<int> lis;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            int pos = it - lis.begin();

            if (it == lis.end())
                lis.push_back(nums[i]);
            else
                *it = nums[i];

            left[i] = pos + 1;
        }

        lis.clear();

        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            int pos = it - lis.begin();

            if (it == lis.end())
                lis.push_back(nums[i]);
            else
                *it = nums[i];

            right[i] = pos + 1;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            if (left[i] > 1 && right[i] > 1) {
                int mountain = left[i] + right[i] - 1;
                ans = min(ans, n - mountain);
            }
        }

        return ans;
    }
};