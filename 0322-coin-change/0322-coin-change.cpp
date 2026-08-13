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
        vector<vector<long long >>dp(n+1,vector<long long>(amount+1,-1));
        int ans=solve(0,n,coins,amount,dp);
        if(ans==INT_MAX) 
            return -1;
            
        return ans;
    }
};