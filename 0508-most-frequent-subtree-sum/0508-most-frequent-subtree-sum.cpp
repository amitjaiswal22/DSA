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
    unordered_map<int,int>mp;
     int solve(TreeNode* root) {
        if (root == nullptr) return 0; // base case
        
        // compute subtree sum recursively
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        int total = root->val + leftSum + rightSum;
        
        // record frequency
        mp[total]++;
        
        return total;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<int>ans;
        int maxcount=1;
        set<int>s;
        unordered_map<int,int>mp1;
        for(auto p:mp){
         s.insert(p.second);
        }
        for(auto p:mp){
            if(p.second==*s.rbegin()){
                  ans.push_back(p.first);
            }
        }
        return ans;
    }
};