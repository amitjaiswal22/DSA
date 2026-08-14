class Solution {
    int mp[2001][2001];
int  check(int i, int j,string &s){
     int l=i;int r=j;
     if(mp[l][r]!=-1)
        return mp[l][r];
     int ans=0;   
     while(l<r){
        if(s[r]!=s[l])
            {
                ans+=1;
            }
            l++;
            r--;
     }
     return mp[i][j]=ans;
}
public:
     long long  solve(int i,int n, string &s,int k,vector<vector<int>>&dp){
        if(i>=n &&k==0){
              return 0;
        }
        if(k<0)
           return INT_MAX;
        long long  ans=INT_MAX;
        if(dp[i][k]!=-1)
            return dp[i][k];
        for(int j=i;j<n;j++){
             long long  res=check(i,j,s);
             ans=min(ans,res+solve(j+1,n,s,k-1,dp));
        }   
        return dp[i][k]=ans;
     }
    int palindromePartition(string s, int k) {
        int n=s.size();
        memset(mp,-1,sizeof(mp));
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans=solve(0,n,s,k,dp);
        return ans; 
    }
};