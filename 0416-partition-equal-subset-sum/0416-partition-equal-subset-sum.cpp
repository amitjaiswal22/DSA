class Solution {
public:
   

   
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
              sum+=nums[i];
        }
        if(sum%2)
            return false;
      
      vector<vector<bool>>dp(n+1,vector<bool>(sum/2+1,false));
      for(int i=0;i<=n;i++){
         dp[i][0]=1;
      }
      for(int i=n-1;i>=0;i--){
        for(int j=1;j<=sum/2;j++){
            bool n_take=dp[i+1][j];
            bool take=false;
            if(j>=nums[i])
                take=dp[i+1][j-nums[i]];
    dp[i][j]=take||n_take;
        }
    
      }
      return dp[0][sum/2];



    }
};