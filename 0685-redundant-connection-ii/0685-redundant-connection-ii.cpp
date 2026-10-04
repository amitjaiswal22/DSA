class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        parent[pv] = pu;
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

     
        vector<int> parentNode(n + 1, 0);

        int edge1 = -1;
        int edge2 = -1;

        for (int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            if (parentNode[v] != 0) {

                // v already has a parent
                edge1 = parentNode[v] - 1;
                edge2 = i;

            } else {
                parentNode[v] = i + 1;
            }
        }

        // ------------------------------------------------
        // Step 2: DSU
        // Ignore edge2 temporarily
        // ------------------------------------------------

        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {

            // Ignore second parent edge
            if (i == edge2)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];

            if (!unite(u, v)) {

                // Cycle exists

                if (edge1 != -1)
                    return edges[edge1];

                return edges[i];
            }
        }

        // ------------------------------------------------
        // Step 3: No cycle after removing edge2
        // Therefore edge2 is redundant
        // ------------------------------------------------

        return edges[edge2];
    }
};