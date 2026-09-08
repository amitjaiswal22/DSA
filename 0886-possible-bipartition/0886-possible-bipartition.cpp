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
    bool possibleBipartition(int n, vector<vector<int>>& graph) {
        
        unordered_map<int,vector<int>>adj;
       
             for(auto it:graph){
                  adj[it[0]].push_back(it[1]);
                  adj[it[1]].push_back(it[0]);
             }
        
        vector<int>visited(n+1,-1);
         for(int i=1;i<=n;i++){
             if(visited[i]==-1){
                   visited[i]=0;
                   if(dfs(i,n,visited,adj)==0)
                       return false;
             }
         }
        return 1;
    }
};