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
      vector<bool>dp(sum/2+1,false);
     
         dp[0]=1;
      
       for (int i = 0; i < n; i++) {

            for (int j = sum/2; j >= nums[i]; j--) {

                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

      return dp[sum/2];



    }
};