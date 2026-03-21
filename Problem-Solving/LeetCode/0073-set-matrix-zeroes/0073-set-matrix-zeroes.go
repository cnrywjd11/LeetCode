func setZeroes(matrix [][]int)  {
    zeroRow := make(map[int]bool)
    zeroCol := make(map[int]bool)
    for i:=0;i< len(matrix);i++ {
        for j := 0; j< len(matrix[0]);j++ {
            if matrix[i][j] == 0 {
                zeroRow[i] = true
                zeroCol[j] = true
            }
        }
    }
    for ki, vi := range zeroRow {
        if vi {
            for j:=0;j< len(matrix[0]);j++ {
                matrix[ki][j] = 0
            }
        }
    }
    for kj, vj := range zeroCol {
        if vj {
            for i:=0;i< len(matrix);i++ {
                matrix[i][kj] = 0
            }
        }
    }
}