class Solution {
public:int n,k;
   int solve(int i,vector<int>&arr,vector<int>&dp){
    if(i>=n||i<0)
       return 0;
       if(dp[i]!=INT_MIN)
           return dp[i];
    int take=arr[i]+solve(i+k,arr,dp);
    return dp[i]=take;  
   }
    int maximumEnergy(vector<int>& energy, int K) {
         n=energy.size();
          k=K;
          int ans=INT_MIN;
          vector<int>dp(n,INT_MIN);
          for(int i=0;i<n;i++){
            ans=max(ans,solve(i,energy,dp));
          }
        return ans;  
    }
};