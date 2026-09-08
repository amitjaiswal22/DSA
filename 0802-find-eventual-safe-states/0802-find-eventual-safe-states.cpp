class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        vector<int>ans;
        int n=edges.size();
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
             for(int j=0;j<edges[i].size();j++){
                adj[edges[i][j]].push_back(i);
                indegree[i]++;
             }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
              q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto v:adj[node]){
        indegree[v]--;
        if(indegree[v]==0)
         q.push(v);
        }
        }
        sort(ans.begin(),ans.end());
   return ans;
    }
};