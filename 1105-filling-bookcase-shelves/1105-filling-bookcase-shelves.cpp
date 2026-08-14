class Solution {
public:
    int solve(int i,int n,vector<vector<int>>&books,int sw,int w,int h,  vector<vector<int>>&dp){
        if(i>=n){
            return h;
        }
        if(dp[i][w]!=-1)
           return dp[i][w];
        int new_self=h+solve(i+1,n,books,sw,books[i][0],books[i][1],dp);
           int same_self=INT_MAX;
        if(w+books[i][0]<=sw){
                same_self=solve(i+1,n,books,sw,w+books[i][0],max(h,books[i][1]),dp);
        }
         return dp[i][w]=min(same_self,new_self);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>>dp(n,vector<int>(shelfWidth+1,-1));
        int ans=solve(0,n,books,shelfWidth,0,0,dp);
        return ans;
    }
};