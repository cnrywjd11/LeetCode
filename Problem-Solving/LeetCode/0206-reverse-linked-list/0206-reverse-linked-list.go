/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    // [1, 2] -> [2, 1]
    // [] -> []
    if head == nil {
        return nil
    }
    nodes := make([]*ListNode, 0)
    node := head
    for {
        nodes = append(nodes, node)
        if node.Next == nil {
            break;
        }
        node = node.Next
    }    
    newHead := nodes[len(nodes)-1]
    for i := len(nodes)-1;i>=1;i-- {
        node = nodes[i]
        node.Next = nodes[i-1]
    }
    nodes[0].Next = nil
    return newHead
}