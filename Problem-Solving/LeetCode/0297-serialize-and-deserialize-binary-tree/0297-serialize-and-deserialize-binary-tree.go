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
	cur := fmt.Sprint(node.Val)
	var left, right string
	if node.Left == nil {
		left = "L"
	} else {
		left = streamSerialize(node.Left)
	}
	if node.Right == nil {
		right = "L"
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
	dataSlice := strings.Split(data, ",")
	var idx int
	return StreamDeserialize(dataSlice, &idx)
}

func StreamDeserialize(dataSlice []string, idx *int) *TreeNode {
  // [1, 2, L, L, 3, 4, L, L, 5, L, L]
  // [1, L, L]
	if dataSlice[*idx] == "L" {
		*idx = *idx + 1
  	return nil
	}
	strVal := dataSlice[*idx]
	val, _ := strconv.Atoi(strVal)
	node := &TreeNode {
		Val: val,
	}
	*idx = *idx + 1
	
	node.Left = StreamDeserialize(dataSlice, idx)
	node.Right = StreamDeserialize(dataSlice, idx)
	
	return node
}