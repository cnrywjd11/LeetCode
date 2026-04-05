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
    str := streamSerialize(root)
    return str
}

func streamSerialize(node *TreeNode) string {
    cur := fmt.Sprint(node.Val)
    var left, right string
    if(node.Left == nil) {
        left = "l"
    } else {
        left = streamSerialize(node.Left)
    }
    if(node.Right == nil) {
        right = "l"
    } else {
        right = streamSerialize(node.Right)
    }
    return fmt.Sprintf("%s,%s,%s", cur, left, right)
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
    if data == "" {
        return nil
    }
    splitSlice := strings.Split(data, ",")
    var idx int
    root := streamDeserialize(splitSlice, &idx)
    return root
}

func streamDeserialize(slice []string, idx *int) (*TreeNode) {
    if len(slice[*idx:]) == 1 {
        *idx = *idx + 1
        return nil
    }
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
    
    left := streamDeserialize(slice, idx)
    node.Left = left

    right := streamDeserialize(slice, idx)
    node.Right = right

    return node
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */