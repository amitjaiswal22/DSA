class Solution {
public:int ans=0; 
    int  solve(unordered_map<int,vector<int>>&adj,int i,string &s ){
        int l=0;
        int m=0;
        for(auto v:adj[i]){
             int child=solve(adj,v,s);
             if(s[v]==s[i])
                continue;
             if(child>l){
                m=l;
                l=child;
             }        
             else{
                if(child>m)
                     m=child;
             }
               
        }
        ans=max(ans,1+l+m);
        return 1+l;
        
    }
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,vector<int>>adj;
        int n=parent.size();
        for(int i=1;i<n;i++){
              adj[parent[i]].push_back(i);
        }
        solve(adj,0,s);
        return ans;
    }
};