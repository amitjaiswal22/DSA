class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
     vector<int>vis(n,-1);
   queue<int>q;
   q.push(s);
   vis[s]=1;
   while(!q.empty()){
    int m=q.size();
    for(int i=0;i<m;i++){
        int node=q.front();
         q.pop();
         if(node==d)
            return 1;
         for(auto v:adj[node]){
             if(vis[v]==-1)
              {
                 vis[v]=1;
                 q.push(v);
              }
         }   

    }
   }
   return false;
    }
};