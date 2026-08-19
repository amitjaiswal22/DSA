class Solution {
public:
    int solve(int i,int j,int n,int m,string&s,string &t,vector<vector<int>>&dp){
        if(i>=n||j>=m)
             return 0;
         if(dp[i][j]!=-1)
            return dp[i][j];    
        int take=0;
           if(s[i]==t[j]){
               take=1+solve(i+1,j+1,n,m,s,t,dp);

           }   
         int take_i=solve(i+1,j,n,m,s,t,dp);
         int take_j=solve(i,j+1,n,m,s,t,dp);
         return dp[i][j]=max(take,max(take_i,take_j));    
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        /*int ans=solve(0,0,n,m,text1,text2,dp);
        return ans;*/
       for(int i=n-1;i>=0;i--){
         for(int j=m-1;j>=0;j--){
            int take=0;
           if(text1[i]==text2[j]){
               take=1+dp[i+1][j+1];
           }   
         int take_i=dp[i+1][j];
         int take_j=dp[i][j+1];
         dp[i][j]=max(take,max(take_i,take_j)); 
         }
       } 
       return dp[0][0];
    }
};