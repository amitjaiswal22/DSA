class Solution {
public:
     vector<int>parent;
     vector<int>rank;
     int find(int x){
          if(x==parent[x])
               return x;
               return parent[x]=find(parent[x]);
     }
    void Union(int u,int v){
         int par_u=find(u);
         int par_v=find(v);
         if(par_u==par_v){
                  return;
         }
         // Union by rank
        if (rank[par_u] > rank[par_v]) {
            parent[par_v] = par_u;
        }
        else if (rank[par_v] > rank[par_u]) {
            parent[par_u] = par_v;
        }
        else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
               parent[i]=i;
        }

        for(int i=0;i<n;i++){
               int u=edges[i][0]-1;
               int v=edges[i][1]-1;
               int par_u=find(u);
               int par_v=find(v);
               if(par_u==par_v)
                   return edges[i];
               else
                  Union(u,v);    
        }
        return {};
    }
};