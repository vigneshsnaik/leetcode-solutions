func solve(grid [][]int, x, y, maxX, maxY, empty int) int {
	if x >= maxX || x < 0 || y >= maxY || y < 0 || grid[y][x] == -1 {
		return 0
	}
	if grid[y][x] == 2 {
		if empty == 0 {
			return 1
		} else {
			return 0
		}
	}
	grid[y][x] = -1
	res := solve(grid, x+1, y, maxX, maxY, empty-1) +
		solve(grid, x-1, y, maxX, maxY, empty-1) +
		solve(grid, x, y+1, maxX, maxY, empty-1) +
		solve(grid, x, y-1, maxX, maxY, empty-1)
	grid[y][x] = 0
	return res
}

func uniquePathsIII(grid [][]int) int {
	maxY, maxX := len(grid), len(grid[0])
	empty := maxX * maxY
				startX, startY := 0,0 
	for y := 0; y < maxY; y++ {
		for x := 0; x < maxX; x++ {
			if grid[y][x] == 1 {
				startX, startY = x, y
				empty--
			} else if grid[y][x] == -1 {
				empty--
			}
		}
	}
	return solve(grid, startX, startY, maxX, maxY, empty)
}