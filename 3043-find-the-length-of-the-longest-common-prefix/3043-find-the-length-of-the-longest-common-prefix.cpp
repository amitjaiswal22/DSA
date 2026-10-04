class Solution {
public:   struct TrieNode {
        TrieNode* child[10];

        TrieNode() {
            for (int i = 0; i < 10; i++) {
                child[i] = nullptr;
            }
        }
    };
    void insert(TrieNode* root, int num) {
        TrieNode* curr = root;

        string s = to_string(num);

        for (char ch : s) {
            int idx = ch - '0';

            if (curr->child[idx] == nullptr) {
                curr->child[idx] = new TrieNode();
            }

            curr = curr->child[idx];
        }
    }
        int getPrefixLength(TrieNode* root, int num) {
        TrieNode* curr = root;
        string s = to_string(num);

        int len = 0;

        for (char ch : s) {
            int idx = ch - '0';

            if (curr->child[idx] == nullptr) {
                break;
            }

            curr = curr->child[idx];
            len++;
        }

        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
             TrieNode* root = new TrieNode();

        // Insert all numbers of arr1
        for (int num : arr1) {
            insert(root, num);
        }

        int ans = 0;

        // Find longest prefix for numbers in arr2
        for (int num : arr2) {
            ans = max(ans, getPrefixLength(root, num));
        }

        return ans;
    }
};