func solve(nums [] int ) int {
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

func rob(nums []int) int {
      n := len(nums)

    if n == 1 {
        return nums[0]
    }

    nums1 := []int{}
    for i := 0; i < n-1; i++ {
        nums1 = append(nums1, nums[i])
    }

    nums2 := []int{}
    for i := 1; i < n; i++ {
        nums2 = append(nums2, nums[i])
    }

    ans := solve(nums1)
    ans1 := solve(nums2)

    return max(ans, ans1)
    
}