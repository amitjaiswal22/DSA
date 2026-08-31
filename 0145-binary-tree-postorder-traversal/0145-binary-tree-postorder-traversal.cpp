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
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int>ans;
        if(root==nullptr)
           return ans;
           stack<pair<TreeNode*,int>>st;
           st.push({root,1});
           while(!st.empty()){
            TreeNode * node=st.top().first;
            int v=st.top().second;
            st.pop();
            if(v==1){
            

             st.push({node,v+1});
                  if(node->left){
                        st.push({node->left,1});
                  }
            }
            else if(v==2){
                  st.push({node,v+1});
                  if(node->right)
                      st.push({node->right,1});
                  
                 
            }
            else ans.push_back(node->val);
           }
           return ans;
    }
};