class Solution {
public:
   long long  solve(int i,int n,vector<int>&num,unordered_map<int,long long>&mp){
     if(i>=n-1){
        return 0;
     }
     if(mp.find(i)!=mp.end())
        return mp[i];
     long long  ans=INT_MAX;
     for(int j=1;j<=num[i];j++){
          ans=min(ans,1+solve(i+j,n,num,mp));
     }
     return mp[i]=ans;
   }
    int jump(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,long long>mp; 
        int ans=solve(0,n,nums,mp);
        return ans;
    }
};