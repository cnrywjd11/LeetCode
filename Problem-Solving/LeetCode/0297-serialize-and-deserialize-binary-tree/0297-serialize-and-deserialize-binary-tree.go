/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Codec struct {
    
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    if root == nil {
        return ""
    }
    return streamSerialize(root)
}

func streamSerialize(node *TreeNode) string {
    if node == nil {
        return "l"
    }
    cur := fmt.Sprint(node.Val)
    left := streamSerialize(node.Left)
    right := streamSerialize(node.Right)
    return fmt.Sprintf("%s,%s,%s", cur, left, right)
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
    if data == "" {
        return nil
    }
    splitSlice := strings.Split(data, ",")
    var idx int
    return streamDeserialize(splitSlice, &idx)
}

func streamDeserialize(slice []string, idx *int) (*TreeNode) {
    strVal := slice[*idx]
    if strVal == "l" {
        *idx = *idx + 1
        return nil
    }
    val, _ := strconv.Atoi(strVal)
    node := &TreeNode{
        Val: val,
    }
    *idx = *idx + 1
    
    node.Left = streamDeserialize(slice, idx)
    node.Right = streamDeserialize(slice, idx)
    return node
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */