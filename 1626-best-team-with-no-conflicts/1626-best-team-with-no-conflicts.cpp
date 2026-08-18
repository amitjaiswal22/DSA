class Solution {
public:
   int solve(int i,int prev,int n,vector<vector<int>>&arr,vector<vector<int>>&dp){
       if(i>=n)
          return 0;
          if(dp[i][prev+1]!=-1)
               return dp[i][prev+1];
       int take=0;
       if(prev==-1|| arr[i][1]>=arr[prev][1])
           take=arr[i][1]+solve(i+1,i,n,arr,dp);
    /* if(prev!=-1&&arr[i][1]==arr[prev][1]&&arr[i][0]==arr[prev][0])  
          take=arr[i][1]+solve(i+1,i,n,arr,dp); */
       int not_take=solve(i+1,prev,n,arr,dp);
       return dp[i][prev+1]=max(take,not_take);       
   }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<vector<int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});

        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(0,-1,n,arr,dp);
        return ans;
    }
};