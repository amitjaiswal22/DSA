class Graph {
public:
     vector<vector<int>>adj;
     int n;
    Graph(int a, vector<vector<int>>& edges) {
        n=a;
          adj=vector<vector<int>>(n,vector<int>(n,1e9));
          for(int i=0;i<n;i++){
                adj[i][i]=0;
          }
          for(auto e:edges){
               adj[e[0]][e[1]]=e[2];
          }
           for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                      adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }}}
    }
    
    void addEdge(vector<int> edge) {
        if(adj[edge[0]][edge[1]]<=edge[2])
             return ;

           adj[edge[0]][edge[1]]=edge[2];
           for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        adj[i][j]=min(adj[i][j],adj[i][edge[0]]+adj[edge[1]][j]+edge[2]);
                }
           }   
    }
    
    int shortestPath(int node1, int node2) {
        if(adj[node1][node2]==1e9)
            return -1;
          return adj[node1][node2];  
     }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */