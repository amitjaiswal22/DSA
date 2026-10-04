class Solution {
public:
    struct TrieNode{
       vector<TrieNode*>child;
       bool isTerminal;
       TrieNode(){
           isTerminal=false;
           child.resize(26,nullptr);
       } 
    };
    void insert(TrieNode * root,string word){
            TrieNode* curr=root;
            for(auto ch:word){
                  int ind=ch-'a';
                  if(curr->child[ind]==nullptr)
                    curr->child[ind]=new TrieNode();
                   curr=curr->child[ind]; 
            }
            curr->isTerminal=true;
    }
    TrieNode* root;
   void solve(TrieNode *root,string& ans){
         TrieNode* curr=root;
           if(curr->isTerminal){
                    return;
            }
         int cnt=0;
         TrieNode* p=nullptr;
         int q=0;
         for(int i=0;i<26;i++){
            if(curr->child[i]!=nullptr){
               cnt++;
               p=curr->child[i];
               q=i;
            }
         }
         if(cnt==1){
            ans+=(q+'a');
          
            
             solve(p,ans);
             return ;
            
         }
         return ;
             
   }
           

    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
         root=new TrieNode();
        for(int i=0;i<n;i++){
              insert(root,strs[i]);
              if(strs[i]=="")
                  return "";
        }
         string ans="";     
          solve(root,ans);
            return ans;       
    }
};