class Solution {
public:
    int maxDotProduct(vector<int>& str1, vector<int>& str2) {
         int n=str1.size();
        int m=str2.size();
        vector<vector<long long >>dp(n+1,vector<long long >(m+1,INT_MIN));
        for(int i=n-1;i>=0;i--){
              for(int j=m-1;j>=0;j--){
                  long long  take=str1[i]*str2[j]+max(0LL,dp[i+1][j+1]);
                    long long  take_i=dp[i+1][j];
                    long long  take_j=dp[i][j+1];
                    dp[i][j]=max(take,max(take_i,take_j));


              }
        }
        return dp[0][0];
    }
};