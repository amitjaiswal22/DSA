class Solution {
public:
   int dp[20][2][1024][2];
   int solve(int i,int t,int mask,int st,string&s){
    if(i==s.size())
        return 1;
     if(dp[i][t][mask][st]!=-1)
         return dp[i][t][mask][st];
     int l=t?s[i]-'0':9 ;
     int ans=0;
     for(int d=0;d<=l;d++){
        int new_t=t&&(s[i]-'0'==d);
       if(!st&&d==0){
           ans+=solve(i+1,new_t,mask,0,s);
       }
       else{
        if(mask&(1<<d)){
              continue
;        }
    ans+=solve(i+1,new_t,mask|(1<<d),1,s);
 
       }
     }   
     return dp[i][t][mask][st]=ans;   
   }
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int unique=solve(0,1,0,0,s);
        return unique-1;
    }
};