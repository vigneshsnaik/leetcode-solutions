func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return nil
	}
	pad := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	res := []string{""}
	for _, digit := range digits {
		tmp := []string{}
		letters := pad[digit-'0']
		for _, letter := range letters {
			for _, s := range res {
				tmp = append(tmp, s+string(letter))
			}
		}
		res = tmp
	}
    return res
}