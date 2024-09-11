func minBitFlips(start int, goal int) int {
	res := start ^ goal
	count := 0
	for res != 0 {
		count += res & 1
		res >>= 1
	}
	return count
}