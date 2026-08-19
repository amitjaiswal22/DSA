class Solution {
public:  int dp[1001][1001];
    bool solve(int i,int j,string &s){
        int l=i;int r=j;
        if(dp[l][r]!=-1)
           return dp[l][r];
        while(i<=j){
              if(s[i]!=s[j]){
                     return dp[i][j]=0;
              }
              i++;
              j--;
        }
        return dp[l][r]=1;
    }
    int countSubstrings(string s) {
        int maxi=0;
        int n=s.size();
        int end=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
             for(int j=i;j<n;j++){
                     if(solve(i,j,s))
                           maxi+=1;
             }
        }
        return maxi;
    }
};