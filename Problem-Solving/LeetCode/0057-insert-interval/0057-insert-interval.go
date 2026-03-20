func insert(intervals [][]int, newInterval []int) [][]int {
    n := len(intervals)
    if n == 0 {
        return [][]int{newInterval}
    }
    
    output := make([][]int, 0)
    idx := 0

    for ;idx < n && intervals[idx][1] < newInterval[0];idx++ {
        output = append(output, intervals[idx])  
    }
    
    for ;idx < n && newInterval[1] >= intervals[idx][0] ;idx++ {
        newInterval[0] = min(intervals[idx][0], newInterval[0])
        newInterval[1] = max(intervals[idx][1], newInterval[1])
    }
    output = append(output, newInterval)

    for ;idx < n; idx++ {
        output = append(output, intervals[idx])
    }

    return output
}