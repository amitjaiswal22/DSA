class Solution {
public:

    int ans = 0;

    int solve(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        ans += abs(left);
        ans += abs(right);

        return left + right + root->val - 1;
    }

    int distributeCoins(TreeNode* root) {

        solve(root);

        return ans;
    }
};