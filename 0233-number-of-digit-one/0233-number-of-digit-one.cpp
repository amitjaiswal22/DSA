class Solution {
public:
      int dp[20][2][20];
      bool vis[20][2][20];
      int solve(int i,int t,int cnt,string&s){
          if(i==s.size())
               return cnt;
          if(dp[i][t][cnt]!=-1){
                return dp[i][t][cnt];
          } 
         
          int limt=t?s[i]-'0':9;
          int ans=0;
          for(int d=0;d<=limt;d++){
            int newt=t&&(d==s[i]-'0');
            int newcnt=cnt;
            if(d==1)
                newcnt++;
            ans+=solve(i+1,newt,newcnt,s);    
          }  
          return dp[i][t][cnt]=ans;  
             
      }
    int countDigitOne(int n) {
        string s=to_string(n);
         memset(dp, -1, sizeof(dp));
        return solve(0,1,0,s);
    }
};