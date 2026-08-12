class Solution {
public:
    int solve(int i,int n,string&s,unordered_map<int,long long>&mp){
    if(i>=n)
        return 1;
     if(s[i]-'0'==0)
         return 0;
     if(mp.find(i)!=mp.end())
         return mp[i];    
     long long  ans=0;
    if(i+1<n)
     if((s[i]-'0'==1)||((s[i]-'0'==2)&&(s[i+1]-'0'<=6)))
        ans+=solve(i+2,n,s,mp);

     ans+=solve(i+1,n,s,mp);
     return mp[i]=ans;   

            
    }
    int numDecodings(string s) {
        int n=s.size();
        unordered_map<int,long long >mp;
        int ans=solve(0,n,s,mp);
        return ans;
    }
};