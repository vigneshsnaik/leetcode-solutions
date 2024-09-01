func construct2DArray(original []int, m int, n int) [][]int {
    var res [][]int
    if m*n != len(original) {
        return res
    }
    for i := 0; i < m; i++ {
        res = append(res, original[i*n : (i+1)*n])
    }
    return res
}