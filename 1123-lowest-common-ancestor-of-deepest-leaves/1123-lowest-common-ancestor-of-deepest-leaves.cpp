class Solution {
public:

    unordered_map<TreeNode*, vector<TreeNode*>> up;
    unordered_map<TreeNode*, int> depth;

    void dfs(TreeNode* root, TreeNode* par) {

        if(root == nullptr)
            return;

        depth[root] = depth[par] + 1;

        up[root].resize(20);

        up[root][0] = par;

        for(int j=1;j<20;j++) {

            if(up[root][j-1] != nullptr)
                up[root][j] =
                    up[up[root][j-1]][j-1];
        }

        dfs(root->left, root);
        dfs(root->right, root);
    }

    TreeNode* lca(TreeNode* p, TreeNode* q) {

        if(depth[p] < depth[q])
            swap(p,q);

        int diff = depth[p] - depth[q];

        for(int j=0;j<20;j++) {

            if(diff & (1<<j))
                p = up[p][j];
        }

        if(p == q)
            return p;

        for(int j=19;j>=0;j--) {

            if(up[p][j] != up[q][j]) {

                p = up[p][j];
                q = up[q][j];
            }
        }

        return up[p][0];
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        if(root == nullptr)
            return nullptr;

        depth[nullptr] = -1;

        // Build binary lifting table
        dfs(root, nullptr);

        queue<TreeNode*> q;
        q.push(root);

        vector<TreeNode*> leaves;

        while(q.empty() == 0) {

            int n = q.size();

            // These are the nodes at current level
            leaves.clear();

            for(int i=0;i<n;i++) {

                auto node = q.front();
                q.pop();

                leaves.push_back(node);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        // leaves now contains ALL nodes
        // at the deepest level

        TreeNode* ans = leaves[0];

        for(int i=1;i<leaves.size();i++) {

            ans = lca(ans, leaves[i]);
        }

        return ans;
    }
};