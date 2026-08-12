func numDecodings(s string) int {
	n := len(s)

	prev := 1
	prev1 := 0

	for i := n - 1; i >= 0; i-- {
		curr := 0

		if s[i]-'0' == 0 {
			curr = 0
		} else {
			curr += prev

			if i+1 < n {
				if s[i]-'0' == 1 ||
					(s[i]-'0' == 2 && s[i+1]-'0' <= 6) {
					curr += prev1
				}
			}
		}

		prev1 = prev
		prev = curr
	}

	return prev
}