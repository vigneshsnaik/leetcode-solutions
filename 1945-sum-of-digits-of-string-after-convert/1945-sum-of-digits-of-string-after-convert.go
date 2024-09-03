func getLucky(s string, k int) int {
	res := 0
	for _, c := range s {
		if c < 'j' {
			res += int(c-'a') + 1
		} else if c < 't' {
			res += int(c-'a') - 8
		} else {
			res += int(c-'a') - 17
		}
	}
	for {
		k--
		if k == 0 {
			break
		}
		sum := 0
		for res > 0 {
			sum += res % 10
			res /= 10
		}
		res = sum
	}
	return res
}