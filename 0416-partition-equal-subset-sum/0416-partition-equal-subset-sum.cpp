class Solution {
public:

    bool solve(int i, int n, vector<int>& nums,
               int tar, vector<vector<int>>& dp) {

        // We found the required sum
        if (tar == 0)
            return true;

        // No elements left or target became negative
        if (i >= n || tar < 0)
            return false;

        // Already calculated
        if (dp[i][tar] != -1)
            return dp[i][tar];

        // Take nums[i]
        bool take = solve(
            i + 1,
            n,
            nums,
            tar - nums[i],
            dp
        );

        // Don't take nums[i]
        bool notTake = solve(
            i + 1,
            n,
            nums,
            tar,
            dp
        );

        return dp[i][tar] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        // Odd sum can never be divided equally
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(0, n, nums, target, dp);
    }
};