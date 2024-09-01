func dfs(grid [][]byte, dp [][][]int, y, x, st int) bool {
	if st < 0 {
		return false
	}
	if y < 0 || x < 0 {
		return false
	}
	if dp[y][x][st] != -1 {
		return dp[y][x][st] == 1
	}
	tmp := st
	if grid[y][x] == ')' {
		st++
	} else {
		st--
	}
	if x == 0 && y == 0 {
		return st == 0
	}
	result := (dfs(grid, dp, y-1, x, st) || dfs(grid, dp, y, x-1, st))
	if result {
		dp[y][x][tmp] = 1
		return true
	} else {
		dp[y][x][tmp] = 0
		return false
	}
}

func hasValidPath(grid [][]byte) bool {
    Y := len(grid)
    X := len(grid[0])
    maxState := Y + X
    dp := make([][][]int, Y)
    for i := range dp {
        dp[i] = make([][]int, X)
        for j := range dp[i] {
            dp[i][j] = make([]int, maxState+1)
            for k := range dp[i][j] {
                dp[i][j][k] = -1
            }
        }
    }
    return dfs(grid, dp, Y-1, X-1, 0) 
}