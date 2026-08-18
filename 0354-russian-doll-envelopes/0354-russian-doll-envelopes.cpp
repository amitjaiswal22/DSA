class Solution {
public:
    int solve(int i,int prev,int n,vector<vector<int>>&arr,vector<vector<int>>&dp){
          if(i>=n)
             return 0;
          int take=0;
          if(dp[i][prev+1]!=-1)
              return dp[i][prev+1];
          if(prev==-1||(arr[i][0]>arr[prev][0]&&arr[i][1]>arr[prev][1]))
              take=1+solve(i+1,i,n,arr,dp);
          int not_take=solve(i+1,prev,n,arr,dp);
         return dp[i][prev+1]=max(take,not_take);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       /* int n=envelopes.size();
        vector<vector<int>>en2;
        for(int i=0;i<n;i++){
                en2.push_back({envelopes[i][1],envelopes[i][0]});
        }
        sort(envelopes.begin(),envelopes.end());
        sort(en2.begin(),en2.end());
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans1=solve(0,-1,n,envelopes,dp);
              vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        int ans2=solve(0,-1,n,en2,dp2);
        return max(ans1,ans2);*/
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> lis;

        for (int i = 0; i < n; i++) {
            int h = envelopes[i][1];

            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }

        return lis.size();
    }
};