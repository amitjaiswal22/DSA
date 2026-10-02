class TrieNode{
    public:
       vector<TrieNode*>child;
       bool isTerminal;
       TrieNode(){
        isTerminal=0;
        child.resize(26);
        for(int i=0;i<26;i++){
               child[i]=nullptr;
        }
       }
    
};  
    class Trie {
public:
TrieNode * root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr=root;
        for(char ch:word){
            int ind=ch-'a';
            if(curr->child[ind]==nullptr){
                curr->child[ind]=new TrieNode();
            }
            curr=curr->child[ind];
        }
        curr->isTerminal=1;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(auto ch:word){
            int ind=ch-'a';
            if(!curr->child[ind])
               return 0;
           curr=curr->child[ind];    
        }
        return curr->isTerminal;
    }
    
    bool startsWith(string prefix) {
          TrieNode* curr=root;
        for(auto ch:prefix){
            int ind=ch-'a';
            if(!curr->child[ind])
               return 0;
           curr=curr->child[ind];    
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */