
class Solution {
public:
  struct TrieNode{
        TrieNode* left;
        TrieNode* right;

  };
  void insert(TrieNode * root,int num){
    TrieNode* curr=root;
    for(int i=31;i>=0;i--){
           int ith_bit=(num>>i)&1;
           if(ith_bit){
                 if(curr->right==nullptr)
                        curr->right=new TrieNode();
                  curr=curr->right;      
           }
           else{
                   if(curr->left==nullptr)
                        curr->left=new TrieNode();
                  curr=curr->left;  
           }

    }
  }
   int solve(TrieNode* root,int num){
    TrieNode* curr=root;
    int ans=0;
    for(int i=31;i>=0;i--){
           int ith_bit=(num>>i)&1;
           if(ith_bit){
                 if(curr->left!=nullptr){
                    ans+=pow(2,i);
                    curr=curr->left;
                 }
                 else{
                        curr=curr->right;
                 }
           }
           else{

              if(curr->right!=nullptr){
                    ans+=pow(2,i);
                    curr=curr->right;
                 }
                 else{
                        curr=curr->left;
                 }


           }
    }
    return ans;
   }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        TrieNode* root=new TrieNode();

        for(int i=0;i<n;i++){
                insert(root,nums[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
                int maxxor=solve(root,nums[i]);
                ans=max(ans,maxxor);
        }
        return ans;

    }
};