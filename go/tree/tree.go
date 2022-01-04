package main

import "fmt"

type node struct {
	val   interface{}
	left  *node
	right *node
}

var root *node

func preOrderPrint(node *node) {
	if node == nil {
		return
	}
	fmt.Println("root->val ", node.val)
	preOrderPrint(node.left)
	preOrderPrint(node.right)
}

func addNode(node *node, curr *node) {
	if curr == nil {
		root = node
	}

	if curr.left == nil && curr.right != nil {
		addNode(node, curr.right)
	}
	if curr.left != nil && curr.right == nil {
		addNode(node, curr.left)
	}

}

func main() {
	root := &node{}
	root.val = "root1"

}
