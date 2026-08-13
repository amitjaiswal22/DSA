class Solution {
public:
    vector<string> simplifiedFractions(int n) {
       set<string>s;
       for(int i=1;i<=n;i++){
           
            for(int j=1;j<i;j++){
                if(__gcd(i,j)!=1)
                   continue;
                string p=to_string(j)+"/"+to_string(i);
                s.insert(p);
            }
       }
            vector<string>ans;
            for( auto t:s){
                   ans.push_back(t);
            }
            return ans;
       
    }
};