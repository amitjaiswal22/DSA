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
    unordered_map<TreeNode*,vector<int>>dp;
    int solve(TreeNode * root,int cnt){
          if(root==nullptr){
                return 0;
          }
          if(dp.find(root)==dp.end())
              dp[root]={-1,-1};
          if(dp.find(root)!=dp.end()&&dp[root][cnt]!=-1)
             return dp[root][cnt];
        int take_left=solve(root->left,0)+solve(root->right,0);
        int take=0;
        if(cnt==0){
               take=root->val+solve(root->left,1)+solve(root->right,1);
        }
        else 
         take=solve(root->left,0)+solve(root->right,0);
        return dp[root][cnt]=max(take,take_left);
    }
    int rob(TreeNode* root) {
        dp.clear();
        dp[root]={-1,-1};
        int ans=solve(root,0);
        return ans;
    }
};