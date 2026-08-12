class Solution {
public:
    int solve(int i,int n,vector<int>&nums,int tar){
        if(i>=n){
             return tar==0;
        }
        int take=solve(i+1,n,nums,tar+nums[i]);
        int not_take=solve(i+1,n,nums,tar-nums[i]);
        return take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=solve(0,n,nums,target);
        return ans;
    }
};