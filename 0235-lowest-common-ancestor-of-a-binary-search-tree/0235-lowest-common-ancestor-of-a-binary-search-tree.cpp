/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
vector<vector<int>>v;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

         if(p==root||q==root||root==nullptr)
            return root;
            TreeNode* left=lowestCommonAncestor(root->left,p,q);
            TreeNode* right=lowestCommonAncestor(root->right,p,q);
            if(left!=nullptr&&right!=nullptr)
               return root;

        if(left!=nullptr)
           return left;
      return right; 
    }
};