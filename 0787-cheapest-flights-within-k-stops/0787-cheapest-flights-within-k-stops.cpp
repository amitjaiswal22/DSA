class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>dist(n,1e9);
        for(vector<int>&vec:flights){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        int level=0;
        while(!q.empty()&&level<=k){
            int N=q.size();
            while(N--){
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                for(auto p:adj[u]){
                    int v=p.first;
                     int w=p.second;
                     if(dist[v]>d+w){
                           dist[v]=d+w;
                           q.push({v,d+w});
                     }
                }
            }
            level++;
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};