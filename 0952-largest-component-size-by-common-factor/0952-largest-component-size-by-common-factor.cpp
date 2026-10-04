class Solution {
public:
    vector<int> parent;
    vector<int> sizet;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v) {

        int par_u = find(u);
        int par_v = find(v);

        if (par_u == par_v)
            return;

        if (sizet[par_u] < sizet[par_v]) {
            parent[par_u] = par_v;
            sizet[par_v] += sizet[par_u];
        }
        else {
            parent[par_v] = par_u;
            sizet[par_u] += sizet[par_v];
        }
    }

    int largestComponentSize(vector<int>& nums) {

        int n = nums.size();

        parent.resize(n);
        sizet.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {

                if (x % p == 0) {

                    // p is a prime factor
                    if (mp.count(p)) {
                        Union(i, mp[p]);
                    }
                    else {
                        mp[p] = i;
                    }

                    // Remove all occurrences of p
                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }

            // Remaining x is also a prime factor
            if (x > 1) {

                if (mp.count(x)) {
                    Union(i, mp[x]);
                }
                else {
                    mp[x] = i;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, sizet[find(i)]);
        }

        return ans;
    }
};