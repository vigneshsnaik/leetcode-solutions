func gameOfLife(board [][]int) {
	m := len(board)
	n := len(board[0])
	dirs := [][2]int{
		{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
		{0, 1}, {1, -1}, {1, 0}, {1, 1},
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			sum := 0
			for _, dir := range dirs {
				x := i + dir[0]
				y := j + dir[1]
				if x >= 0 && x < m && y >= 0 && y < n && (board[x][y]&1) != 0 {
					sum++
				}
			}
			if sum < 2 || sum > 3 {
				board[i][j] &= ^2 
			} else if sum == 3 {
				board[i][j] |= 2
			} else if board[i][j]&1 != 0 {
				board[i][j] |= 2
			}
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			board[i][j] >>= 1
		}
	}
}