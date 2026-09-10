class Solution {
public:int dx[4]={1,-1,0,0};
   int dy[4]={0,0,1,-1};
   
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int ans=INT_MAX;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
              for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0&&x<n&&y>=0&&y<m){
                    int new_dist=dist[i][j]+grid[x][y];
                    if(new_dist<dist[x][y]){
                        dist[x][y]=new_dist;
                        
                            q.push({x,y});
                        

                    }
                                  }

        }
        }
        return dist[n-1][m-1];
    }
};