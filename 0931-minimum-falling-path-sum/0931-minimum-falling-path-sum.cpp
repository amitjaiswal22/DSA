class Solution {
public:
    long long  solve(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp){
       if(j>=m||j<0)
              return INT_MAX;   
        if(i==n-1)
            return arr[i][j];
         if(dp[i][j]!=INT_MAX)
               return dp[i][j];
        long long  take_d=solve(i+1,j,n,m,arr,dp);
        long long  take_dl=solve(i+1,j-1,n,m,arr,dp);
        long long  take_dr=solve(i+1,j+1,n,m,arr,dp);
        return dp[i][j]=arr[i][j]+min(take_d,min(take_dl,take_dr));    
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long long  ans=INT_MAX;
        for(int i=0;i<m;i++){
            vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
               ans=min(ans,solve(0,i,n,m,matrix,dp));
        }
        return ans;
    }
};