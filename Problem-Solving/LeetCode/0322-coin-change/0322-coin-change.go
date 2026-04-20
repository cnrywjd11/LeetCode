func coinChange(coins []int, amount int) int {
  dp := make([]int, amount+1)
  for i:=0;i<len(dp);i++ {
    dp[i] = 987654321
  }
  sort.Ints(coins)
  for i:=0;i<len(coins);i++ {
    if coins[i] > amount {
      coins = coins[:i+1]
      break
    }
  }
  return coinNumbers(coins, amount, dp)
}

// 만족하는 최소의 coins 개수를 반환
// 점화식: f(amount) = f(amount-coins[n-1 ~ 0]) + 1
func coinNumbers(coins []int, amount int, dp []int) int {
  if amount == 0 {
    dp[amount] = 0
    return 0
  }
  if dp[amount] != 987654321 {
    return dp[amount]
  }
  for i:=len(coins)-1;i>=0;i-- {
    if(amount - coins[i] >= 0) {
      next := coinNumbers(coins, amount - coins[i], dp) // [1, 2, 5] -> amount: 4: upper bound
      if(next == -1) {
        continue
      }
      dp[amount] = min(dp[amount], next + 1)
    }
  }
  if dp[amount] == 987654321 {
    dp[amount] = -1                          
  }
  return dp[amount]
}