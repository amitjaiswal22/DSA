func rob(nums []int) int {
    n:=len(nums)
      if n==1 {  
          return nums[0]
      }
     prev1:=0
     prev:=0  
     for i:=n-1;i>=0;i-- {
        curr:=max(prev1,prev+nums[i])
        prev=prev1
        prev1=curr
     }  
     return max(prev,prev1)

}