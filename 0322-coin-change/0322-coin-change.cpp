class Solution {
public:

long long solve(int i,int n,vector<int>&coins,int amt,vector<vector<long long >>&dp){
        if(i>=n)
            return amt==0?0:INT_MAX;  
         if(dp[i][amt]!=-1)
             return dp[i][amt];    
        long long  take=INT_MAX;
        if(amt>=coins[i])
           take=1+solve(i,n,coins,amt-coins[i],dp);
        long long  n_take=solve(i+1,n,coins,amt,dp);
         return dp[i][amt]=min(take,n_take);        
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long >>dp(n+1,vector<long long>(amount+1,1e9));
       /* int ans=solve(0,n,coins,amount,dp);
        if(ans==INT_MAX) 
            return -1;
            
        return ans;*/
       for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=n-1;i>=0;i--){
                for(int j=1;j<=amount;j++){
                    long long n_take=dp[i+1][j];
                    long long take =1e9;
                    if(j>=coins[i])
                     take=1+dp[i][j-coins[i]];
                   dp[i][j]=min(take,n_take);  
                }
        }
        if(dp[0][amount]==1e9)
             return -1;
          return dp[0][amount];   

    }
};