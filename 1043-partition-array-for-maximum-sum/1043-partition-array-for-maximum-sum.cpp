class Solution {
public:
    int solve(int i,int n,vector<int>&arr,int k,vector<int>&dp){
        if(i>=n)
            return 0;
         if(dp[i]!=-1)
            return dp[i];   
         int ans=-1e8;
         int maxi=-1e8;
         int start=i;
         for(int j=i;j<n;j++){
                 if(j-i+1>k){
                      maxi=INT_MIN;
                      start=j;
                 }
                  maxi=max(maxi,arr[j]);
                    ans=max(ans,(j-start+1)*maxi+solve(j+1,n,arr,k,dp));
         }   
         return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,n,arr,k,dp);
        return ans;
    }
};