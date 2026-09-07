class Solution {
public:
  bool dfs(int i,int n, vector<int>&vis,unordered_map<int,vector<int>>&adj){

    for(auto it:adj[i]){
        if(vis[it]==-1){
               vis[it]=1-vis[i];
               if(dfs(it,n,vis,adj)==0)
                   return 0;;
        }
        else{
              if(vis[it]==vis[i])
                  return false;  
        }

    }
    return 1;
  }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
             for(auto it:graph[i]){
                  adj[i].push_back(it);
                  adj[it].push_back(i);
             }
        }
        vector<int>visited(n,-1);
         for(int i=0;i<n;i++){
             if(visited[i]==-1){
                   visited[i]=0;
                   if(dfs(i,n,visited,adj)==0)
                       return false;
             }
         }
        return 1;
    }
};