class TrieNode{
    public:
    vector<pair<TrieNode*,int>>child;
    bool isTerminal;
    TrieNode(){
        isTerminal=false;
        child.resize(26);
        for(int i=0;i<26;i++){
           child[i]={nullptr,0};
        }
    }
};
class MapSum {
public:
TrieNode* root;
unordered_map<string, int> mp;
    MapSum() {
        root=new TrieNode();
    }
    
    void insert(string key, int val) {
         int delta = val - mp[key];
        mp[key] = val;
          TrieNode* curr=root;
          for(auto ch:key){
            int ind=ch-'a';
            if(!curr->child[ind].first){
                    curr->child[ind].first=new TrieNode();
            }
             curr->child[ind].second+=delta;
             curr=curr->child[ind].first;
          }
          curr->isTerminal=1;
    }
    
    int sum(string prefix) {
        int ans=0;
         TrieNode* curr=root;
          for(auto ch:prefix){
            int ind=ch-'a';
            if(!curr->child[ind].first){
                       return 0;
            }
             ans=curr->child[ind].second;
             curr=curr->child[ind].first;
          }
         return ans;

    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */