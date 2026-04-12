func countSubstrings(s string) int {
    totalSubStrs := 0
    subStrs := func(l, r int) int {
        ret := 0
        for 0<=l && r < len(s) {
            if s[l] == s[r] {
                ret++
                l--
                r++
            } else {
                break
            }
        }
        return ret
    }
    for i:=0;i<len(s);i++ {
        totalSubStrs = totalSubStrs + subStrs(i, i)
    }
    for i:=0;i<len(s)-1;i++ {
        totalSubStrs = totalSubStrs + subStrs(i, i+1)
    }
    return totalSubStrs
}