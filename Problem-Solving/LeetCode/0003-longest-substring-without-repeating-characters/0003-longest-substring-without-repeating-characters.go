func lengthOfLongestSubstring(s string) int {
    mp := make(map[rune]int)
    var length, maxLen, start int
    
    for i, c := range s {
        // mp[c] 가 없을 때
        if _, ok := mp[c]; !ok {
            mp[c] = i
            length++
            maxLen = max(maxLen, length)
            continue
        }
        // 의미 없는 mp[c], lazy delete, mp[c] < start
        if mp[c] < start{
            mp[c] = i
            length++
            maxLen = max(maxLen, length)
            continue
        }

        // 의미 있는 mp[c]
        prevIdx := mp[c]
        start = prevIdx + 1
        length = i - start + 1
        mp[c] = i
    }

    return maxLen
}