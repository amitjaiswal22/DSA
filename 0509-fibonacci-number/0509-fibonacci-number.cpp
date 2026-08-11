class Solution {
public:
    int fib(int n) {
        int prev0=0;
        int prev1=1;
        if(n==0)
           return 0;
           if (n==1){
              return 1;
           }
          for(int i=2;i<=n;i++){
               int curr=prev0+prev1;
                prev0=prev1;
                prev1=curr;
          } 
          return prev1;
    }
};