class Solution {
public:
   double solve(string u,string v,unordered_map<string,vector<pair<string,double>>>&adj){

    double ans=1.00000;
    set<string>visited;
    queue<pair<string,double>>q;
    q.push({u,1.00000});
     visited.insert(u);
     while(!q.empty()){
       string node=q.front().first;
       double val=q.front().second;
       q.pop();
       if(node==v)
         return val;
       for(auto t:adj[node]){
             if(visited.find(t.first)==visited.end()){
                   visited.insert(t.first);
                   q.push({t.first,val*t.second});
             }
       }  

      
     }

 return -1.00000;}

   
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<values.size();i++){
                adj[equations[i][0]].push_back({equations[i][1],values[i]});
                adj[equations[i][1]].push_back({equations[i][0],(1.0/values[i])});
        }
        vector<double>ans;
       
        for(auto q:queries){
               string u=q[0];
               string v=q[1];
                if(adj.find(u)==adj.end()||adj.find(v)==adj.end()){
                     ans.push_back(-1.00000);
                }
                else{
                      if(u==v){
                            ans.push_back(1.00000);
                      }

                      else{
                           double  p=solve(u,v,adj);
                           ans.push_back(p);
                      }
                }
               
                       }
        return ans;
    }
};