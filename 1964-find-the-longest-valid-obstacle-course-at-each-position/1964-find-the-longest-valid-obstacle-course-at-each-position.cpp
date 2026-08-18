class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n=ob.size();
        vector<int>lis,dp(n);
        for(int i=0;i<n;i++){
            auto it=upper_bound(lis.begin(),lis.end(),ob[i]);
            int index=it-lis.begin();
            if(it==lis.end())
                lis.push_back(ob[i]);
            else{
                   *it=ob[i];
            }    
            dp[i]=index+1;
        }
        return dp;
    }
};