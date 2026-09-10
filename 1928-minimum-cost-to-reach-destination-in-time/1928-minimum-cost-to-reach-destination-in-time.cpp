class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        int n=passingFees.size();
        vector<vector<int>>dist(n,vector<int>(maxTime+1,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({passingFees[0],{0,0}});
        dist[0][0]=passingFees[0];
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int cost=t.first;
            int time=t.second.first;
            int node=t.second.second;
            if(node==n-1)
                return cost;
             if(cost>dist[node][time])
                continue; 
                for(auto it:adj[node]){
                    int v=it.first;
                    int tim=it.second;
                    int c=passingFees[v];

                    if(time+tim<=maxTime&&cost+c<dist[v][time+tim]){
                        dist[v][time+tim]=cost+c;
                        pq.push({cost+c,{time+tim,v}});
                    }
                }  
        }
        int ans=1e9;
        for(int i=0;i<=maxTime;i++){
            ans=min(ans,dist[n-1][i]);
        }
    return ans==1e9?-1:ans;
        
    }
};