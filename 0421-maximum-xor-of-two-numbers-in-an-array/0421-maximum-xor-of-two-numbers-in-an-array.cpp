class Solution {
public:

    struct TrieNode {
        TrieNode* child[2];

        TrieNode() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* curr = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }

            curr = curr->child[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* curr = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            // To make XOR bit = 1,
            // we want the opposite bit.
            int opposite = 1 - bit;

            if (curr->child[opposite]) {
                ans |= (1 << i);
                curr = curr->child[opposite];
            }
            else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {

        // Insert all numbers into Trie
        for (int num : nums) {
            insert(num);
        }

        int ans = 0;

        // Find best XOR for every number
        for (int num : nums) {
            ans = max(ans, getMaxXOR(num));
        }

        return ans;
    }
};