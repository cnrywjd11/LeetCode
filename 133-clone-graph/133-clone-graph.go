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
    
    var visited [101]bool
    var nodes [101]*Node
    
    return clone(visited[:], nodes[:], node)
}

func clone(visited []bool, nodes []*Node, node *Node) *Node {
    nn := &Node {
        Val: node.Val,
        Neighbors: make([]*Node, len(node.Neighbors)),
    }
 
    visited[node.Val] = true
    nodes[node.Val] = nn
    
    for i, n := range node.Neighbors {
        if !visited[n.Val] {
            clone(visited, nodes, n)
        }
        nn.Neighbors[i] = nodes[n.Val]
    }
    
    return nn 
}