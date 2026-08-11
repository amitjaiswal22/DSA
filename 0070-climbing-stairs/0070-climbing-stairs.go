func climbStairs(n int) int {
    if n==1 ||n==2{
         return n;
    }
    prev1:=1;
    prev2:=2
    for i:=3;i<=n;i++{
        curr:=prev2+prev1
        prev1=prev2
        prev2=curr
    }
    return prev2
}