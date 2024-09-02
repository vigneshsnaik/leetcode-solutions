func isValid(board [][]byte, x, y int, c byte) bool {
	for i := 0; i < 9; i++ {
		if board[i][y] == c {
			return false
		}
		if board[x][i] == c {
			return false
		}
		if board[3*(x/3)+i/3][3*(y/3)+i%3] == c {
			return false
		}
	}
	return true
}
func solve(board [][]byte) bool {
	for x := 0; x < 9; x++ {
		for y := 0; y < 9; y++ {
			if board[x][y] == '.' {
				for c := byte('1'); c <= '9'; c++ {
					if isValid(board, x, y, c) {
						board[x][y] = c
						if solve(board) {
							return true
						}
						board[x][y] = '.'
					}
				}
				return false
			}
		}
	}
	return true
}

func solveSudoku(board [][]byte) {
	solve(board)
}