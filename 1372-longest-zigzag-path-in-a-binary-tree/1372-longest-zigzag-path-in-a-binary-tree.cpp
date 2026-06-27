class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int dir, int length) {
        if (!root) return;
        ans = max(ans, length);

        if (dir == 0) { // last move was left, go right next
            dfs(root->right, 1, length + 1);
            dfs(root->left, 0, 1); // restart from left child
        } else { // last move was right, go left next
            dfs(root->left, 0, length + 1);
            dfs(root->right, 1, 1); // restart from right child
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, 0, 1);  // start zigzag going left
        dfs(root->right, 1, 1); // start zigzag going right
        return ans;
    }
};
