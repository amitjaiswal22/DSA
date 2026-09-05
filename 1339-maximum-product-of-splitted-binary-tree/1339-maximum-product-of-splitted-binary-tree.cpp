/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
long long  ans=INT_MIN;
long long  tot=0;
int solve(TreeNode* root){
     if(root==nullptr)
         return 0;
     long long left=solve(root->left);
     long long  right=solve(root->right);
long long subtreeSum = left + right + root->val;
        long long otherSum = tot - subtreeSum;

        ans = max(ans, subtreeSum * otherSum);

        return subtreeSum;
    }
    long long  solveSum(TreeNode* root){
           if(root==nullptr)
              return 0;
              return (long long)root->val+solveSum(root->left)+solveSum(root->right);  
    }
    int maxProduct(TreeNode* root) {
        tot=solveSum(root);
        solve(root);
        return ans % 1000000007;
    }
};