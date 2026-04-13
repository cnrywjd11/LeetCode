func longestPalindrome(s string) string {
	// "a" -> "a"
  // "aa" -> "aa"
  // "bab" -> "bab"
  // "baba" -> "bab" 또는 "aba"
  
  longestStr := ""
  
 //  중간 지점 idx 또는 idx, idx+1를 잡고, 왼쪽, 오른쪽 하나씩 늘려간 문자열이 팰린드롬을 만족하는지 체크를 한다.
  // 중간 지점은 0~마지막index까지 순회
  for i:=0;i<len(s);i++ {
    tmpStr := longestPalindromeWithIdx(s, i, i)
    if len(longestStr) < len(tmpStr) {
      longestStr = tmpStr
    }
  }
  for i:=0;i<len(s)-1;i++ {
    tmpStr := longestPalindromeWithIdx(s, i, i+1)
    if len(longestStr) < len(tmpStr) {
      longestStr = tmpStr
    }
  }
  return longestStr
}

func longestPalindromeWithIdx(s string, l, r int) string {
  ret := ""
  for 0 <= l && r < len(s) {
    if(s[l] == s[r]) {
      ret = s[l:r+1]
      l--
      r++
    } else {
      return ret
    }
  }
  return ret
}