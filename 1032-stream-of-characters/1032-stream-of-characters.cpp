class StreamChecker {
public:struct TrieNode{
    vector<TrieNode*>child;
      bool isTerminal;
      TrieNode(){
           isTerminal=false;
           child.resize(26,nullptr);
      }
};
void insert(TrieNode* root,string word){
    TrieNode* curr=root;
    for(auto ch:word){
           int ind=ch-'a';
           if(curr->child[ind]==nullptr){
                curr->child[ind]=new TrieNode();
           }
           curr=curr->child[ind];
    }
    curr->isTerminal=true;
}
TrieNode* root;
    StreamChecker(vector<string>& words) {
        root=new TrieNode();
        for(auto ch:words){
               reverse(ch.begin(),ch.end());
              insert(root,ch);
        }
        
    }
     string stream;

       bool query(char letter) {

        stream.push_back(letter);

        TrieNode* curr = root;

        // Start from the latest character
        for (int i = stream.size() - 1; i >= 0; i--) {

            int ind = stream[i] - 'a';

            // No matching path
            if (curr->child[ind] == nullptr)
                return false;

            curr = curr->child[ind];

            // Found a complete word
            if (curr->isTerminal)
                return true;
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */