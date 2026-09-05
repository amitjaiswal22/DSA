class Solution {
public:
    int ans = 0;

    // {isBST, minValue, maxValue, sum}
    struct Info {
        bool isBST;
        int mini;
        int maxi;
        int sum;
    };

    Info solve(TreeNode* root) {
        if (root == nullptr) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check whether current subtree is BST
        if (left.isBST && right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            int sum = left.sum + right.sum + root->val;

            ans = max(ans, sum);

            return {
                true,
                min(root->val, left.mini),
                max(root->val, right.maxi),
                sum
            };
        }

        // Current subtree is not a BST
        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};