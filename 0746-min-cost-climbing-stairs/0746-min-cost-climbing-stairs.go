func minCostClimbingStairs(cost []int) int {
    prev:=0;
    prev1:=0

    for i :=len(cost)-1;i>=0;i-- {
        curr:=cost[i]+min(prev1,prev)
        prev1=prev
        prev=curr

    }
    return min(prev1,prev)

}