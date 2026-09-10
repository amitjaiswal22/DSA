class Solution {
public:unordered_map<int,pair<int,int>>mp;
    int minCost(vector<vector<int>>& grid) {
        mp[1]={0,1};
        mp[2]={0,-1};
        mp[3]={1,0};
        mp[4]={-1,0};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        q.push({0,0});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0&&y>=0&&x<n&&y<m){
                  int newdist=dist[i][j];
                  auto p=mp[grid[i][j]];
                  if(p.first!=dx[k]||p.second!=dy[k]){
                       newdist+=1;
                  }
                  if(newdist<dist[x][y]){
                    dist[x][y]=newdist;
                    q.push({x,y});
                  }
            



                }
            }
        }
        return dist[n-1][m-1];
    }
};