class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
     unordered_map<int,vector<int>>adj;
     for(auto e: prerequisites){
           adj[e[1]].push_back(e[0]);
     }   
     vector<bool>ans;
     for(auto qt:queries){
            int u=qt[0];
            int v=qt[1];
            queue<int>q;
            vector<bool>visted(n,false);
            q.push(v);
            bool p=false;
            visted[v]=1;
            while(!q.empty()){
                   int top=q.front();
                   q.pop();
                   if(top==u){
                      p=true;
                      break;
                   }
                   for(auto t:adj[top]){
                       if(visted[t]==false){
                           visted[t]=true;
                           q.push(t);
                       }
                   }


            }
            ans.push_back(p);


     }
     return ans;
    }
};