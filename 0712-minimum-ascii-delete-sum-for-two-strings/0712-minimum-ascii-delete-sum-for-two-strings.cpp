class Solution {
public:
    int minimumDeleteSum(string word1, string word2) {
          int n=word1.size();
        int m=word2.size();
      vector<int> prev(m + 1, 0);
        for(int j = m - 1; j >= 0; j--) {
            prev[j] = word2[j] + prev[j + 1];
        }
        for(int i=n-1;i>=0;i--){
          vector<int> curr(m + 1, 0);

            // word2 is exhausted
            // Delete remaining characters of word1
            curr[m] = word1[i] + prev[m];
              for(int j=m-1;j>=0;j--){
                   int take=1e8;
                   if(word1[i]==word2[j])
                    take=prev[j+1];
                    int take_i=prev[j]+word1[i];
                    int take_j=curr[j+1]+word2[j];
                    curr[j]=min(take_i,min(take_j,take));  

              }
              prev=curr;
        }
        return prev[0];
    }
};