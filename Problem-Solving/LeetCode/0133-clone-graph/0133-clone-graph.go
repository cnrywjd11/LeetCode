/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
    if node == nil {
        return nil
    }
    copiedNodes := make([]*Node, 101)
    return dfs(node, copiedNodes)
}

func dfs(node *Node, copiedNodes []*Node) *Node {
    if copiedNodes[node.Val] != nil {
        return copiedNodes[node.Val]
    }
    copiedNode := &Node {
        Val: node.Val,
    }
    copiedNodes[node.Val]= copiedNode
    for _, neighbor := range node.Neighbors {
        copiedNeighbor := dfs(neighbor, copiedNodes)
        copiedNode.Neighbors = append(copiedNode.Neighbors, copiedNeighbor)
    }
    return copiedNode
}