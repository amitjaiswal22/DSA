
class Solution {
public:
    vector<int> segTree;

    void update(int idx, int s, int e, int pos) {
        if (s == e) {
            segTree[idx]++;
            return;
        }

        int mid = s + (e - s) / 2;

        if (pos <= mid)
            update(2 * idx, s, mid, pos);
        else
            update(2 * idx + 1, mid + 1, e, pos);

        segTree[idx] = segTree[2 * idx] + segTree[2 * idx + 1];
    }

    int query(int idx, int s, int e, int l, int r) {
        if (r < s || e < l)
            return 0;

        if (l <= s && e <= r)
            return segTree[idx];

        int mid = s + (e - s) / 2;

        return query(2 * idx, s, mid, l, r) +
               query(2 * idx + 1, mid + 1, e, l, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        if (n == 0) return ans;

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        segTree.assign(4 * m + 4, 0);

        for (int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(vals.begin(), vals.end(), nums[i])
                      - vals.begin() + 1;

            // Count previously processed elements with smaller ranks
            ans[i] = query(1, 1, m, 1, pos - 1);

            // Insert current element into the tree
            update(1, 1, m, pos);
        }

        return ans;
    }
};
