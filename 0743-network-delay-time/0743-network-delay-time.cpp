class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto t:times ){
               adj[t[0]].push_back({t[1],t[2]});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int t =pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto v:adj[u]){
                int cost=v.second;
                int node=v.first;
                if(t+cost<dist[node]){
                    dist[node]=t+cost;
                    pq.push({t+cost,node});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)
               return -1;
               ans=max(ans,dist[i]);
        }
        return ans;
    }
};