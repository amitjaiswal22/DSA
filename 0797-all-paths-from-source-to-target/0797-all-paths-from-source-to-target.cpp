class Solution {
public:  vector<vector<int>>ans;
   void dfs(int u,int n,unordered_map<int,vector<int>>&adj,vector<int>temp){
    if(u==n-1){
          
          ans.push_back(temp);
           return  ;
    }
    for(auto v:adj[u]){
           temp.push_back(v);
           dfs(v,n,adj,temp);
           temp.pop_back();
    }
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      
        int m=graph.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<m;i++){
             for(auto it:graph[i]){
                   adj[i].push_back(it);
             }
        }
        vector<int>temp;
        temp.push_back(0);
        dfs(0,m,adj,temp);
        return ans;
    }
};