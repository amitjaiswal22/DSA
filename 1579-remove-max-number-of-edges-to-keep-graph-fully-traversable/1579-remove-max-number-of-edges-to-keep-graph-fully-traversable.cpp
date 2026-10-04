class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int u, int v) {

        int par_u = find(u);
        int par_v = find(v);

        if (par_u == par_v)
            return false;

        if (rank[par_u] > rank[par_v]) {
            parent[par_v] = par_u;
        }
        else if (rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        }
        else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }

        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        // Alice DSU
        vector<int> parentA(n + 1);
        vector<int> rankA(n + 1, 0);

        // Bob DSU
        vector<int> parentB(n + 1);
        vector<int> rankB(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parentA[i] = i;
            parentB[i] = i;
        }

        // Local find
        auto findA = [&](int x) {
            while (x != parentA[x]) {
                parentA[x] = parentA[parentA[x]];
                x = parentA[x];
            }
            return x;
        };

        auto findB = [&](int x) {
            while (x != parentB[x]) {
                parentB[x] = parentB[parentB[x]];
                x = parentB[x];
            }
            return x;
        };

        int componentsA = n;
        int componentsB = n;

        int removed = 0;

        // Type 3 first
        for (auto &e : edges) {

            int type = e[0];
            int u = e[1];
            int v = e[2];

            if (type == 3) {

                int pu = findA(u);
                int pv = findA(v);

                if (pu != pv) {

                    parentA[pv] = pu;
                    componentsA--;

                    // Same edge is also used by Bob
                    pu = findB(u);
                    pv = findB(v);

                    if (pu != pv) {
                        parentB[pv] = pu;
                        componentsB--;
                    }

                }
                else {
                    removed++;
                }
            }
        }

        // Type 1 → Alice
        for (auto &e : edges) {

            if (e[0] != 1)
                continue;

            int u = e[1];
            int v = e[2];

            int pu = findA(u);
            int pv = findA(v);

            if (pu != pv) {
                parentA[pv] = pu;
                componentsA--;
            }
            else {
                removed++;
            }
        }

        // Type 2 → Bob
        for (auto &e : edges) {

            if (e[0] != 2)
                continue;

            int u = e[1];
            int v = e[2];

            int pu = findB(u);
            int pv = findB(v);

            if (pu != pv) {
                parentB[pv] = pu;
                componentsB--;
            }
            else {
                removed++;
            }
        }

        if (componentsA != 1 || componentsB != 1)
            return -1;

        return removed;
    }
};