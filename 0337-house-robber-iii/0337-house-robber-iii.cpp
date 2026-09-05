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
unordered_map<TreeNode*,vector<int>>mp;
    int solve(TreeNode* root,int flag){
        if(root==nullptr)
            return 0;

         if(mp.find(root)==mp.end())
               mp[root]={-1,-1};
          if(mp.find(root)!=mp.end()&&mp[root][flag]!=-1){
                return mp[root][flag];
          }       
        int take=0;
        if(flag==0){
                take=root->val+solve(root->left,1)+solve(root->right,1);
        }   
          int not_take=solve(root->left,0)+solve(root->right,0);
          return mp[root][flag]=max(take,not_take);    
    }
    int rob(TreeNode* root) {
        mp.clear();
        mp[root]={-1,-1};
        int ans=solve(root,0);
        return ans;
    }
};