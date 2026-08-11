func fib(n int) int {
    if n==0 || n==1 {
        return n
    }
    prev0 :=0;
    prev1 :=1;
    for  i:=2;i<=n;i++{
        curr:=prev0+prev1;
        prev0=prev1;
        prev1=curr;
    }
    return prev1;
}