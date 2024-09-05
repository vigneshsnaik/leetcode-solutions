func missingRolls(rolls []int, mean int, n int) []int {
	sum := 0
	for _, num := range rolls {
		sum += num
	}
	miss := mean*(n+len(rolls)) - sum
	if miss < n || miss > 6*n {
		return make([]int, 0)
	}
	extra := miss % n
	val := miss / n
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = val
		if i < extra {
			res[i]++
		}
	}
	return res
}