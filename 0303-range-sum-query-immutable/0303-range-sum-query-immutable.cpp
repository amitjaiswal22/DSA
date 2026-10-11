class NumArray {
public:vector<long long >st;
int n;
void build(int i,int s,int e,vector<int>&nums){
    if(s==e){
          st[i]=nums[s];
          return ;
    }
    int m=s+(e-s)/2;
    build(2*i+1,s,m,nums);
    build(2*i+2,m+1,e,nums);
    st[i]=st[2*i+1]+st[2*i+2];
}
    NumArray(vector<int>& nums) {
        n=nums.size();
       st.resize(4*n,0);
       build(0,0,n-1,nums);  
    }
    int query(int i,int s,int e,int l,int r){
       if(r<s||l>e)
           return 0;
       if(l<=s&&e<=r) 
           return st[i];
       int m=s+(e-s)/2;
       int a=query(2*i+1,s,m,l,r);
       int b=query(2*i+2,m+1,e,l,r);
       return a+b;       
    
    }
    int sumRange(int l, int r) {
        return query(0,0,n-1,l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */