class Solution {
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool canBuild(const string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            curr = curr->child[idx];
              if (!curr || !curr->isEnd)
                return false;
        }

        return true;
    }

public:
    string longestWord(vector<string>& words) {
        for (const string& word : words)
            insert(word);

        string ans = "";
        for (const string& word : words) {
            cout<<word<<" ";
            if (canBuild(word)) {
                if (word.length() > ans.length() ||
                    (word.length() == ans.length() && word < ans)) {
                    ans = word;
                    cout<<word<<endl;
                }

            }
            cout<<endl;
        }

        return ans;
    }
};