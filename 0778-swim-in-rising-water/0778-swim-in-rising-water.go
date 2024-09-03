func solve(grid [][]int, dp [][][]int, visited [][]bool, n, x, y, t int) int {
	if x < 0 || y < 0 || x == n || y == n || visited[x][y] {
		return math.MaxInt32
	}
	if x == n-1 && y == n-1 {
		return int(math.Max(float64(t), float64(grid[x][y])))
	}
	if dp[x][y][t] != -1 {
		return dp[x][y][t]
	}
	visited[x][y] = true
	currMax := int(math.Max(float64(t), float64(grid[x][y])))
	dp[x][y][t] = int(math.Min(
		math.Min(
			float64(solve(grid, dp, visited, n, x-1, y, currMax)),
			float64(solve(grid, dp, visited, n, x+1, y, currMax)),
		),
		math.Min(
			float64(solve(grid, dp, visited, n, x, y+1, currMax)),
			float64(solve(grid, dp, visited, n, x, y-1, currMax)),
		),
	))
	visited[x][y] = false
	return dp[x][y][t]
}

func swimInWater(grid [][]int) int {
	n := len(grid)
	dp := make([][][]int, n)
	visited := make([][]bool, n)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, n*n)
			for k := range dp[i][j] {
				dp[i][j][k] = -1
			}
		}
	}
	for i := range visited {
		visited[i] = make([]bool, n)
		for j := range visited[i] {
			visited[i][j] = false
		}
	}
	return solve(grid, dp, visited, n, 0, 0, 0)
}