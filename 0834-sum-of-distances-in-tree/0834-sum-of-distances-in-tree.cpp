class Solution {
public:vector<int>ans;
 vector<int>child;
   int result=0;
   void  dfs(unordered_map<int,vector<int>>&mp,int i,int par){
    for(auto v:mp[i]){
        if(v==par)
           continue;
         dfs(mp,v,i);
        child[i]+=child[v];
        result+=child[v];
    }
      return ;
   }
   void dfs2(unordered_map<int, vector<int>>& mp,
          int i,
          int par,
          int n) {

    for(auto v : mp[i]) {

        if(v == par)
            continue;

        ans[v] = ans[i] - child[v] + n - child[v];

        dfs2(mp, v, i, n);
    }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        child.resize(n,1);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][1]].push_back(edges[i][0]);
            mp[edges[i][0]].push_back(edges[i][1]);
        }
        
         dfs(mp,0,-1);
          ans.resize(n, 0);
             ans[0] = result;
        dfs2(mp, 0, -1, n);
         return ans;
    }
};