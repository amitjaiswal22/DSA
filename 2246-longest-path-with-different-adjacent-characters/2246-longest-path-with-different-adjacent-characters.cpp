class Solution {
public:
 vector<int> child[100001];
    int ans;
    int dfs(string &s,int curr){
        if(child[curr].empty())
          return 1;
       int a=0,b=0;
       for(auto v:child[curr]){
        int len=dfs(s,v);
        ans=max(ans,len);
        if(s[curr]==s[v])
           continue;
         if(len>a){
            b=a;
            a=len;
         }  
         else
             b=max(b,len);
       }   
       ans=max(ans,1+a+b);
       return 1+a;
    }
    int longestPath(vector<int>& parent, string s) {
         int n = parent.size();
        for(int i=1;i<n;i++)child[parent[i]].push_back(i);
         ans = 1;
        dfs(s,0);
        return ans;
    }
};