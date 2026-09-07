class Solution {
public:
   void dfs(int i,int n,vector<int>&vis,vector<vector<int>>&rooms){
        vis[i]=1;
         for(auto it:rooms[i]){
               if(vis[it]==-1)
               dfs(it,n,vis,rooms);
         }
   }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,-1);
        dfs(0,n,visited,rooms);
        for(int i=0;i<n;i++){
             if(visited[i]==-1)
                 return 0;
        }
        return 1;
    }
};