class Solution {
public:
    struct TrieNode{
            vector<TrieNode*>child;
            bool isTerminal;
            string word;
            TrieNode(){
                  child.resize(26,nullptr);
                  isTerminal=false;
                  word ="";
            }
    };
    void insert(TrieNode* root,string word){
         TrieNode* curr=root;
         for(auto ch:word){
               int ind=ch-'a';
               if(curr->child[ind]==nullptr)
                     curr->child[ind]=new TrieNode();
                 curr=curr->child[ind];
         }
         curr->isTerminal=true;
         curr->word =word ;
    }
    vector<string>ans;
    void dfs(vector<vector<char>>&board,int i,int j,TrieNode* curr){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]=='#')
              return ;
          char c=board[i][j];
          if(!curr->child[c-'a']){
                return ;
          }  
          curr=curr->child[c-'a'];
          if(curr->word!=""){
               ans.push_back(curr->word);
               curr->word="";
          }
          board[i][j]='#';
          dfs(board,i+1,j,curr);
           dfs(board,i-1,j,curr);
            dfs(board,i,j+1,curr);
             dfs(board,i,j-1,curr);
                board[i][j]=c;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(int i=0;i<words.size();i++){
                insert(root,words[i]);
        }
        for(int i=0;i<board.size();i++){
              for(int j=0;j<board[i].size();j++){
                    dfs(board,i,j,root);
              }

        }

              return ans;}
    
};