class Solution {
public:
    int n;
    /*long long  solve(int i,int n,vector<int>&cost){
        if(i>=n){
              return  0;
        }
        long long  ans=cost[i]+solve(i+1,n,cost);
        long long  ans2=cost[i]+solve(i+2,n,cost);
        return min(ans,ans2);
    }*/
    
    long long  solve(int i,int n,vector<int>&cost,unordered_map<int,int>&mp){
        if(i>=n){
              return  0;
        }
        if(mp.find(i)!=mp.end())
           return mp[i];
        long long  ans=cost[i]+solve(i+1,n,cost,mp);
        long long  ans2=cost[i]+solve(i+2,n,cost,mp);
        return mp[i]=min(ans,ans2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        if(n==1){
             return cost[0];
        }
        if(n==2){
            return min(cost[0],cost[1]);
        }
        unordered_map<int,int>dp,mp;
        int ans=solve(0,n,cost,dp);
        int ans2=solve(1,n,cost,mp);
        return min(ans,ans2);
    }
};