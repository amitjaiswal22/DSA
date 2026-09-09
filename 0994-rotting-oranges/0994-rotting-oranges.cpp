class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        int rotten=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                     fresh++;
                 if(grid[i][j]==2)
                   {
                    rotten++;
                    q.push({i,j});
                   }    
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
      if(fresh==0)
         return 0;
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
             int x=q.front().first;
             int y=q.front().second;
             q.pop();
             for(int k=0;k<4;k++){
                int r=x+dx[k];
                int c=y+dy[k];
                if(r>=0&&r<n&&c>=0&&c<m&&grid[r][c]==1){
                    grid[r][c]=2;
                    fresh--;
                    q.push({r,c});
                }
             }
           

            }  ans++;
        }
        if(fresh!=0)
             return -1;
        return ans-1;

    }
};