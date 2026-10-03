class Solution {
public:

    struct TrieNode {
        vector<TrieNode*> child;
        set<string> value;
        bool isTerminal;

        TrieNode() {
            child.resize(26, nullptr);
            isTerminal = false;
        }
    };

    void insert(TrieNode* root, string word) {

        TrieNode* curr = root;

        for (char ch : word) {

            int ind = ch - 'a';

            if (curr->child[ind] == nullptr) {
                curr->child[ind] = new TrieNode();
            }

            curr = curr->child[ind];

            curr->value.insert(word);
        }

        curr->isTerminal = true;
    }

    vector<vector<string>> solve(
        TrieNode* root,
        string word) {

        vector<vector<string>> ans;

        TrieNode* curr = root;

        for (char ch : word) {

            int ind = ch - 'a';

            if (curr == nullptr) {
                ans.push_back({});
                continue;
            }

            if (curr->child[ind] == nullptr) {
                curr = nullptr;
                ans.push_back({});
                continue;
            }

            curr = curr->child[ind];

            vector<string> result;

            for (auto s : curr->value) {

                result.push_back(s);

                if (result.size() == 3)
                    break;
            }

            ans.push_back(result);
        }

        return ans;
    }

    vector<vector<string>> suggestedProducts(
        vector<string>& products,
        string searchWord) {

        TrieNode* root = new TrieNode();

        for (string product : products) {
            insert(root, product);
        }

        return solve(root, searchWord);
    }
};