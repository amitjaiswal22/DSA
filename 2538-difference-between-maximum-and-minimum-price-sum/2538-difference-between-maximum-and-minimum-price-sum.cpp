class Solution {
public:long long ans=0;
 vector<long long> downMax;
 vector<long long> downMin;
  void dfs(int i,int par,vector<int>&price){
      downMax[i]=price[i];
      downMin[i]=price[i];
      for(auto v:adj[i]){
        if(v==par)
          continue;
        dfs(v,i,price);
       downMax[i]=max(downMax[i],(long long)price[i]+downMax[v]); 
       downMin[i]=max(downMin[i],(long long)price[i]+downMin[v]);     
      }
  }
  void dfs2(int i,int par,vector<int>&price,long long upMax,long long upMin){
     long long curMax =max(downMax[i],(long long)price[i] + upMax);
     long long curMin =min(downMin[i], (long long)price[i] + upMin);
     ans = max(ans, curMax - curMin);
     long long max1 = 0, max2 = 0;
        int maxNode = -1;

    long long min1 = 0, min2 = 0;
        int minNode = -1;

        for(auto v : adj[i]) {
            if(v == par)
                continue;

            // Maximum child contribution
            if(downMax[v] > max1) {
                max2 = max1;
                max1 = downMax[v];
                maxNode = v;
            }
            else if(downMax[v] > max2) {
                max2 = downMax[v];
            }

            // Minimum child contribution
            if(downMin[v] < min1) {
                min2 = min1;
                min1 = downMin[v];
                minNode = v;
            }
            else if(downMin[v] < min2) {
                min2 = downMin[v];
            }
        }

        for(auto v : adj[i]) {

            if(v == par)
                continue;

            long long mx = upMax;
            long long mn = upMin;

            // If v was giving us the best max,
            // use second best when going into v.
            if(v == maxNode)
                mx = max(mx, max2);
            else
                mx = max(mx, max1);

            // Same idea for minimum.
            if(v == minNode)
                mn = min(mn, min2);
            else
                mn = min(mn, min1);

            dfs2(v,i,price,price[i] + mx,price[i] + mn );
        }



  }
 unordered_map<int,vector<int>>adj;
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
         downMax.resize(n);
        downMin.resize(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,price);
        dfs2(0,-1,price,0,0);
        return ans;
    }
};