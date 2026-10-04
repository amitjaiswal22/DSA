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
          if(par_u==par_v)
             return ;
        if(rank[par_v]>rank[par_u]){
                parent[par_u]=par_v;
        }
         else{
                if(rank[par_u]>rank[par_v])
                   parent[par_v]=par_u;
                 else{
                       rank[par_u]+=1;
                       parent[par_v]=par_u;
                 }  
         }       
        

      }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
             return -1;
          parent.resize(n);
          rank.resize(n,1);
          for(int i=0;i<n;i++)
               parent[i]=i;
         int count=0;
         for(auto e:connections){
                int u=e[0];
                int v=e[1];
                int par_u=find(u);
                int par_v=find(v);
                if(par_u==par_v){
                    count++;
                }
                else{
                       Union(u,v);
                }
               
         }
        

  int com=0;
         for(int i=0;i<n;i++){
          if(find(i)==i)
             com++;
               
         }
            return com-1;
    }
};