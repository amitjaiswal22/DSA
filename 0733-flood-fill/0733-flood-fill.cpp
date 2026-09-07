class Solution {
public:
  int dx[4]={0,0,-1,1};
  int dy[4]={-1,1,0,0};
    int sp;
   void solve(int i,int j,int n,int m,int c,vector<vector<int>>&image){
     image[i][j]=c;
     for(int k=0;k<4;k++){
      int x=i+dx[k];
      int y=j+dy[k];
      if(x>=0&&x<n&&y>=0&&y<m&&image[x][y]==sp)
          solve(x,y,n,m,c,image);
     }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
         sp=image[sr][sc];
           if(sp == color)
        return image;
        solve(sr,sc,n,m,color,image);
        return image;
    }
};