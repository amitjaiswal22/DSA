class Solution {
public:

    int cameras = 0;

    // 0 -> not covered
    // 1 -> camera
    // 2 -> covered

    int solve(TreeNode* root) {

        if (root == nullptr)
            return 2;

        int left = solve(root->left);
        int right = solve(root->right);

        // If any child is not covered,
        // current node must have camera.
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has camera,
        // current node is covered.
        if (left == 1 || right == 1)
            return 2;

        // Both children are covered but
        // neither has camera.
        return 0;
    }

    int minCameraCover(TreeNode* root) {

        if (solve(root) == 0)
            cameras++;

        return cameras;
    }
};