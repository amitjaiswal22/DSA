class Solution {
public:
    int dp[1001][1001];
    bool solve(int i,int j,string &s){
        int l=i;int r=j;
        while(i<=j){
              if(s[i]!=s[j]){
                     return dp[i][j]=0;
              }
              i++;
              j--;
        }
        return dp[l][r]=1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=1;
        int start=0;
        int end=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
             for(int j=i;j<n;j++){
                     if(solve(i,j,s))
                          if(j-i+1>maxi){
                            maxi=j-i+1;
                            start=i;
                            end=j;
                          }
             }
        }
      string ans="";
      for(int k=start;k<=end;k++){
         ans+=s[k];
      }
      return ans;
    }
};