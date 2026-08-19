class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>prev(m+1,0);
        for(int i=n-1;i>=0;i--){
            vector<int>curr(m+1,0);
              for(int j=m-1;j>=0;j--){
                   int take=0;
                   if(word1[i]==word2[j])
                    take=1+prev[j+1];
                    int take_i=prev[j];
                    int take_j=curr[j+1];
                    curr[j]=max(take_i,max(take_j,take));  

              }
              prev=curr;
        }
        return m+n-2*prev[0];
    }
};