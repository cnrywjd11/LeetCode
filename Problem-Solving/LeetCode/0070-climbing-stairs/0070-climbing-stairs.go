func climbStairs(n int) int {
    dp := make([]int, n+1)
    for i:=range(dp) {
        dp[i] = -1
    }
    return distinctWays(n, dp)
}

func distinctWays(n int, dp []int) int {
    if n <=2 {
        return n
    }
    if dp[n] != -1 {
        return dp[n]
    }
    dp[n] = distinctWays(n-1, dp) + distinctWays(n-2, dp)
    return dp[n]
}