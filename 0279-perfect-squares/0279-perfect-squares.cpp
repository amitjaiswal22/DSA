class Solution {
public:
    int numSquares(int t) {
       vector<int>coins;
       for(int i=1;i*i<=t;i++){
             coins.push_back(i*i);
       } 
       int n=coins.size();
       vector<vector<int>>dp(n+1,vector<int>(t+1,1e9));
       for(int i=0;i<=n;i++){
           dp[i][0]=0;
       }
       for(int i=n-1;i>=0;i--){
            for(int j=1;j<=t;j++){
                   int n_take=dp[i+1][j];
                   int take=1e9;
                   if(j>=coins[i]){
                        take=1+dp[i][j-coins[i]];
                   }
                    dp[i][j]=min(take,n_take);
            }
       }
       return dp[0][t];
    }
};