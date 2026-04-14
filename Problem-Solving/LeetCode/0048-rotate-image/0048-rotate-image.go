func rotate(matrix [][]int)  {
    size := len(matrix)
    slices.Reverse(matrix)
    for i:=0;i<size-1;i++ {
        for j:=i+1;j<size;j++ {
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        }
    }
}