class Solution {
public:
   bool solve(int i,int n,string&s, set<string>&st,map<int,bool>&mp){
      if(i>=n)
         return 1;
         if(mp.find(i)!=mp.end())
            return mp[i];
       bool ans=false;
       string temp="";
       for(int j=i;j<n;j++){
           temp+=s[j];
           if(st.find(temp)!=st.end())
              ans=ans||solve(j+1,n,s,st,mp);

       } 
       return mp[i]=ans; 
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string>st(wordDict.begin(),wordDict.end());
        map<int,bool>mp;
        bool ans=solve(0,n,s,st,mp);
        return ans;
    }
};