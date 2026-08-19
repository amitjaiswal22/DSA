class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
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
        string ans="";
        int i=0;
        int j=0;
        while(i<n&&j<m){
           
         if(str1[i] == str2[j]) {

                ans += str1[i];

                i++;
                j++;
            }

            // Take character from str1
            else if(dp[i + 1][j] >= dp[i][j + 1]) {

                ans += str1[i];
                i++;
            }

            // Take character from str2
            else {

                ans += str2[j];
                j++;
            }
        }

        // Remaining characters
        while(i < n) {
            ans += str1[i++];
        }

        while(j < m) {
            ans += str2[j++];
        }

        return ans;
    }
};