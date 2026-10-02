class TrieNode{
        public:
            char data;
            TrieNode* child[26]={};
            bool isTerminal;
            TrieNode(char data){
                this->data=data;
                isTerminal=false;

            }
};

class Trie {
public:
TrieNode* root;
    Trie() {  
        root=new TrieNode('\0');
    }
    
    void insert(string word) {
        solveInsert(root,word,0);
    }
    void solveInsert(TrieNode* root,string word,int i){
            if(word.size()==i){
                   root->isTerminal=1;
                   return ;
            }
            int ind=word[i]-'a';
            if(root->child[ind]==nullptr){
                    root->child[ind]=new TrieNode(word[i]);
            }
            solveInsert(root->child[ind],word,i+1);
    }
    
    bool search(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.size();i++){
                 int ind=word[i]-'a';
                 if(!temp->child[ind]|| temp->child[ind]->data!=word[i]){
                        return false;
                 }
                 temp=temp->child[ind];
        }
        return temp->isTerminal;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(int i=0;i<prefix.size();i++){
            int ind=prefix[i]-'a';
              if(!temp->child[ind]|| temp->child[ind]->data!=prefix[i]){
                        return false;
                 }
                 temp=temp->child[ind];
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