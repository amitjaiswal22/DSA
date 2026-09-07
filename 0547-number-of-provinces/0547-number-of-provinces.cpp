class Solution {
public:
    void dfs(int i,int n,vector<int>&vis,unordered_map<int,vector<int>>&adj){
        vis[i]=1;
        for(auto it:adj[i]){
             if(vis[it]==-1)
                dfs(it,n,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        //vector<vector<int>>adj(n,vector<int>(n,0));
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
              if(i!=j&&isConnected[i][j]==1){
                  adj[i].push_back(j);
                   adj[j].push_back(i);
              }
        }
        vector<int>vis(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
             if(vis[i]==-1)
                 {
                    ans++;
                    dfs(i,n,vis,adj);
                 }
            }
            return ans;
        }
    
};