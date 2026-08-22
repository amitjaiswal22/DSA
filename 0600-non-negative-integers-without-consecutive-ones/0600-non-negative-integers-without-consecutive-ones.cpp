class Solution {
public:
    int dp[32][2][2];
    int solve(int i,int t,int prev,string&s){
        if(i==s.size())
            return 1;
        if(dp[i][t][prev]!=-1)
            return dp[i][t][prev];
        int l=t?s[i]-'0':1;
        int ans=0;
        for(int d=0;d<=l;d++){
             if(prev==1&&d==1)
                 continue;
               int new_t=t&&(s[i]-'0'==d);
               ans+=solve(i+1,new_t,d,s);  
        }        
        return dp[i][t][prev]=ans;
    }
    int findIntegers(int n) {
        string s="";
        while(n>0){
            s+=char(n&1)+'0';
            n>>=1;
        }
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,s);
    }
};