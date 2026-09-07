class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};

   int  dfs(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis){
       vis[i][j]=1;
        int c=1;
       for(int k=0;k<4;k++){
            int new_i=i+dx[k];
            int new_j=j+dy[k];
            if(new_i>=0&&new_i<n&&new_j>=0&&new_j<m&&vis[new_i][new_j]==-1&&grid[new_i][new_j]==1){
                  c+=dfs(new_i,new_j,n,m,grid,vis);
            }
       }
       return c;

   }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==-1 &&grid[i][j]==1)
                     {
                        
                        ans=max(ans,dfs(i,j,n,m,grid,visited));
                     }
            }
        }
        return ans;
    }
};