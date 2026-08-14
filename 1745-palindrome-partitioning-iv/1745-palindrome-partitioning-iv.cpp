class Solution {

public:int mp[2001][2001];
bool check(int i, int j,string &s){
     int l=i;int r=j;
     if(mp[l][r]!=-1)
        return mp[l][r];
     while(l<r){
        if(s[r]!=s[l])
            {
                return mp[l][r]=0;
            }
            l++;
            r--;
     }
     return mp[i][j]=1;
}
bool solve(int i,int n,string &s,int k,vector<vector<int>>&dp){
      if(i>=n){
           return k==0;

      }
      if(k<0)
          return false;
     bool ans=false;
     if(dp[i][k]!=-1)
        return dp[i][k];
     for(int j=i;j<n;j++){
         if(check(i,j,s)){
              ans=ans||solve(j+1,n,s,k-1,dp);
         }

     }
     return dp[i][k]=ans;

}
    bool checkPartitioning(string s) {
        int n=s.size();
        memset(mp,-1,sizeof(mp));
        vector<vector<int>>dp(n,vector<int>(4,-1));
        bool ans=solve(0,n,s,3,dp);
        return ans;
    }
};