class Solution {
public:
    int solve(vector<int>&ob){
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
       return lis.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
         int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> newArr;
            for (int j = i; j < n; j += k)
                newArr.push_back(arr[j]);
            ans += newArr.size() - solve(newArr);
        }
        return ans;
    }
};