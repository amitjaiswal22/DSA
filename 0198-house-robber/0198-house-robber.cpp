class Solution {
public:
  /*Recursion
   int solve(int i,int n,vector<int>&num){
        if(i>=n){
            return 0;
        }
        int take =num[i]+solve(i+2,n,num);
        int not_take=solve(i+1,n,num);
        return max(take,not_take);
   }
   */
  /* Memoization
    int solve(int i,int n,vector<int>&num,unordered_map<int,int>&mp){
        if(i>=n){
            return 0;
        }
        if(mp.find(i)!=mp.end())
           return mp[i];
        int take =num[i]+solve(i+2,n,num,mp);
        int not_take=solve(i+1,n,num,mp);
        return mp[i]=max(take,not_take);
   }*/
    int rob(vector<int>& num) {
       int n=num.size();
      /* unordered_map<int,int>mp,dp;
       int ans=solve(0,n,nums,mp);
       int ans2=solve(1,n,nums,dp);
       return max(ans,ans2);*/ 
       if(n==1)
          return num[0];
       vector<int>dp(n+2,0);
       for(int i=n-1;i>=0;i--){
           dp[i]=max(dp[i+1],dp[i+2]+num[i]);
           
       }
       return max(dp[0],dp[1]);
    }
};