func insert(intervals [][]int, newInterval []int) [][]int {
    if len(intervals) == 0 {
        return [][]int{newInterval}
    }
    output := make([][]int, 0)
    finished := false
    for i, interval := range intervals {
        if finished {
            output = append(output, interval)
            continue
        }
        if interval[1] < newInterval[0] {
            output = append(output, interval)
            if i == len(intervals) -1 {
                output = append(output, newInterval)
            }
        } else if newInterval[1] < interval[0] {
            output = append(output, newInterval, interval)
            finished = true
        } else {
            minStart := min(interval[0], newInterval[0])
            maxEnd := max(interval[1], newInterval[1])
            newInterval[0] = minStart
            newInterval[1] = maxEnd
            if i == len(intervals) -1 {
                output = append(output, newInterval)
            }
        }
    }
    return output
}