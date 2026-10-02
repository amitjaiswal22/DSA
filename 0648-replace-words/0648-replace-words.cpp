class TrieNode{
    public:
      vector<TrieNode*>child;
      bool isTerminal;
      TrieNode(){
        isTerminal=false;
        child.resize(26,nullptr);
      }
};

class Solution {
public:
TrieNode* root;

void insert(TrieNode* root,string word){
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
    string replaceWords(vector<string>& dictionary, string sentence) {
        root=new TrieNode();
        for(auto c:dictionary){
                insert(root,c);
        }
        string ans="";
        string word="";
        for(char ch:sentence){
            if(ch== ' '){
                ans+=solve(word);
                ans+=" ";
                word="";
            }
            else{
                 word+=ch;
            }
        }
        ans+=solve(word);
        return ans;
    
    }
    string solve(string word){
        TrieNode* curr=root;
        string ans="";
        for(char ch:word){
            int ind=ch-'a';
            if(!curr->child[ind]){
                return word;
            }
            curr=curr->child[ind];
            ans+=ch;
            if(curr->isTerminal)
                return ans;
        }
        return word;
    }
};