func chalkReplacer(chalk []int, k int) int {
	sum := 0
	for _, num := range chalk {
		sum += num
	}
	k %= sum
	for i, num := range chalk {
		if k < num {
			return i
		}
		k -= num
	}
	return len(chalk) - 1
}