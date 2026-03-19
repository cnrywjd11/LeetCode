func getSum(a int, b int) int {
    for b != 0{
        carry := (a & b) << 1
        sumWithoutCarry := (a ^ b)
        a = sumWithoutCarry
        b = carry
    }
    return a
}