class Solution {
public:
     int ma;
     int mb;
     long long  dp[23][2][450];
     long long mod=1e9+7;
     int solve(int i, int t,int sum,string& s){
        if(sum>mb)
            return 0;
        if(i>=s.size()){
             return ma<=sum&&sum<=mb; 
        }
        if(dp[i][t][sum]!=-1)
            return dp[i][t][sum];
        int l=t?s[i]-'0':9;
        long long ans=0;
        for(int d=0;d<=l;d++){
            int newt=t&&(s[i]-'0'==d);
             int new_sum=sum+d;
             ans=(ans+solve(i+1,newt,new_sum,s))%mod;
             ans=ans%mod;
        }
        return dp[i][t][sum]=ans; 
     }
     string subtractOne(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }

        if (i >= 0)
            s[i]--;

        // Remove leading zero
        int pos = 0;
        while (pos + 1 < s.size() && s[pos] == '0')
            pos++;

        return s.substr(pos);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
                ma = min_sum;
                mb = max_sum;

       
        memset(dp,-1,sizeof(dp));
        int right=solve(0,1,0,num2);
  
        memset(dp,-1,sizeof(dp));
      string num1MinusOne = subtractOne(num1);

        int left = solve(0,1,0,num1MinusOne);

        return (right-left+mod)%mod
;    }
};