class Solution {
public:
    int minInsertions(string s) {
         string str1=s;
        string str2=s;
        reverse(str2.begin(),str2.end());
         int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
              for(int j=m-1;j>=0;j--){
                  int take=0;
                  if(str1[i]==str2[j])
                      take=1+dp[i+1][j+1];
                    int take_i=dp[i+1][j];
                    int take_j=dp[i][j+1];
                    dp[i][j]=max(take,max(take_i,take_j));


              }
        }
        return n-dp[0][0];
    }
};