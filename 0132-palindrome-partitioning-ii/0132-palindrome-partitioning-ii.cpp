class Solution {
public: int dp[2001][2001];
    bool check(int i,int j, string &s)
       {
         if(dp[i][j]!=-1)
             return dp[i][j];
        while(i<j){
            if(s[i]!=s[j]){
                  return dp[i][j]=0;
            }
            i++;
            j--;
        }
        return dp[i][j]=1;
        }
    int solve(int i,int n,string&s,vector<int>&mp){
         if(i>=n)
            return 0;
         int ans=INT_MAX;
         if(mp[i]!=-1)
              return mp[i];
         for(int j=i;j<n;j++){
              int res=INT_MAX;
              if(check(i,j,s)){
                   res=1+solve(j+1,n,s,mp);
                     ans=min(ans,res); 
              }
           
         }
         return mp[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        vector<int>mp(n,-1);
        int ans=solve(0,n,s,mp);
        return ans-1;
    }
};