class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
    unordered_map<int,vector<int>>adj;
    vector<int>indegree(n,0);
    for(auto e:prerequisites){
         adj[e[1]].push_back(e[0]);
         indegree[e[0]]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
            if(indegree[i]==0){
                  q.push(i);
            }

    }
vector<int>ans;   while(q.empty()==0){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for( auto v:adj[node]){
            indegree[v]--;
            if(indegree[v]==0)
               q.push(v);

        }
    }
    return ans.size()==n;
    }
};