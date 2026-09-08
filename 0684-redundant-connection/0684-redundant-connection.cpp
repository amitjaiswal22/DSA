class Solution {
public:

    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {

        a = find(a);
        b = find(b);

        // Already connected -> cycle
        if (a == b)
            return false;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rankv.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            if (!unite(u, v))
                return {u, v};
        }

        return {};
    }
};