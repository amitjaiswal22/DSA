class NumArray {
public:
    vector<int>segTree;
    int n;
   void build(int idx,int s,int e,vector<int>&nums){
    if(s==e){
            segTree[idx]=nums[s];
            return ;
    }
    int mid=s+(e-s)/2;
    build(2*idx+1,s,mid,nums);
    build(2*idx+2,mid+1,e,nums);
    segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
    return ;
   }
    NumArray(vector<int>& nums) {
         n=nums.size();
        segTree.resize(4*n,0);
        build(0,0,n-1,nums);
    }
    void updateTree(int i,int s,int e,int ind,int val){
        if(s==e){
               segTree[i]=val;
               return;
        }
        int mid=s+(e-s)/2;
        if(ind<=mid){
             updateTree(2*i+1,s,mid,ind,val);
        }
        else{
               updateTree(2*i+2,mid+1,e,ind,val);
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    void update(int index, int val) {
          if(index<0||index>=n)
               return ;
          return updateTree(0,0,n-1,index,val);
    }
    long long query(int i,int s,int e,int l,int r){
            if(r<s||l>e){
                   return 0;
            }
            if(l<=s&&e<=r){
                   return segTree[i];
            }
            int m=s+(e-s)/2;
            long long a=query(2*i+1,s,m,l,r);
            long long b=query(2*i+2,m+1,e,l,r);
            return a+b;
    }
    int sumRange(int l, int r) {
        if(n==0||l<0||r>=n||l>r){
               return 0;
        }
        return query(0,0,n-1,l,r);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */