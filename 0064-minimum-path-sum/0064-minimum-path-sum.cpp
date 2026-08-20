class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prev(m+1,1e7);
        prev[m-1]=grid[n-1][m-1];
       for(int i=n-1;i>=0;i--){
        vector<int>curr(m+1,1e7);
        for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1){
                      curr[j]=grid[i][j];
                }
                else 
                 {
                     int take=grid[i][j]+curr[j+1];
                     int take2=grid[i][j]+prev[j];
                     curr[j]=min(take,take2);
                 }

        }
        prev=curr;
       }
       return prev[0];
    }
};