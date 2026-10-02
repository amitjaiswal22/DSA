class TrieNode{
    public:
      vector<TrieNode*>child;
      bool isTerminal;
      TrieNode(){
         isTerminal=0;
         child.resize(27,nullptr);
      }
};
class WordDictionary {
public:
TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
    for(auto ch:word){
        int ind=ch-'a';
        if(!curr->child[ind]){
               curr->child[ind]=new TrieNode();
        }
        curr=curr->child[ind];
    }
       curr->isTerminal=1;
    }
    
    bool search(string word) {
       return solve(root,word,0);
    }
       bool solve(TrieNode* curr, string& word, int i) {

        // Word completely traversed
        if (i == word.size()) {
            return curr->isTerminal;
        }

        char ch = word[i];

        // Normal character
        if (ch != '.') {
            int ind = ch - 'a';

            if (!curr->child[ind])
                return false;

            return solve(curr->child[ind], word, i + 1);
        }

        // '.' means try all 26 characters
        for (int j = 0; j < 26; j++) {

            if (curr->child[j]) {
                if (solve(curr->child[j], word, i + 1))
                    return true;
            }
        }

        return false;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */