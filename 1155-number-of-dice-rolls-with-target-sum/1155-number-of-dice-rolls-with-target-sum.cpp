class Solution {
public:
    int m=1e9+7;
    int solve(int i,int k,int target,vector<vector<vector<int>>>&dp){
        if(target==0&&i==0)
             return 1;
         if(target==0||i==0)
             return 0;
          if(target<0)
              return 0;
          if(dp[i][k][target]!=-1)
              return dp[i][k][target];    
          int ans=0;
          for(int j=1;j<=k;j++){
               ans=(ans+solve(i-1,k,target-j,dp))%m;
          }           

          return dp[i][k][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(target+1,0)));
        /*int ans=solve(n,k,target,dp);
        return ans; */

         for (int j = 0; j <= k; j++) {
            dp[0][j][0] = 1;
        }
        for(int i=1;i<=n;i++){
              for(int j=1;j<=k;j++){
                for(int t=1;t<=target;t++){
                         int ans=0;
                         for(int l=1;l<=j;l++){
                            if(t-l>=0){
                                ans=(ans+dp[i-1][j][t-l])%m;
                            }
                         }
                         dp[i][j][t]=ans;
                }
            
              }
             
        } 

 return dp[n][k][target];
    }
};