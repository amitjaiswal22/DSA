class Solution {
public:
    bool solve(int i,int n,vector<int>&num,unordered_map<int,bool>&mp){
        if(i>=n-1){
              return 1;
        }
       
     if(mp.find(i)!=mp.end()) 
         return mp[i];
        bool ans=0;
     if(num[i]==0)
       return mp[i]=0;   
    for( int j=1;j<=num[i];j++){
         if(solve(j+i,n,num,mp))
             return mp[i]=1;
    }
    return mp[i]=0;

    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        /*  unordered_map<int,bool>mp;
          bool ans=solve(0,n,nums,mp);
          return ans;*/
          int far=0;
          for(int i=0;i<n;i++){
            if(i>far)
               return 0;
            far=max(far,i+nums[i]);
            if(far>=n-1)
              return 1;   
          }
          return 0;
    }
};