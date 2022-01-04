package main

import (
	"fmt"
	"strconv"
)

type node struct {
	key   int
	value string
	next  [10]*node
}

type prefixTree struct {
	root *node
	size int
}

func createNode(digit int) *node {
	var next [10]*node
	return &node{digit, "", next}
}

func (this *prefixTree) insert(key int, value string) {

	if this.size == 0 {
		this.root = createNode(-1)
	}
	keyRange := strconv.Itoa(key)
	iter := this.root
	for _, digit := range keyRange {
		keyDigit, _ := strconv.Atoi(string(digit))
		//		println(keyDigit)
		if iter.next[keyDigit] == nil {
			iter.next[keyDigit] = createNode(keyDigit)
		}
		iter = iter.next[keyDigit]
	}
	this.size += 1
	iter.value = value
}

func countChildren(iter *node) int {
	count := 0
	for i := 0; i < 10; i++ {
		if iter.next[i] != nil {
			count++
		}
	}
	return count
}

func (this *prefixTree) remove(key int) bool {
	keyRange := strconv.Itoa(key)
	iter := this.root
	var prev *node
	var lastDigit int
	for _, digit := range keyRange {
		keyDigit, _ := strconv.Atoi(string(digit))
		prev = iter
		lastDigit = keyDigit
		treenode := iter.next[keyDigit]
		if treenode == nil {
			return false
		}
		iter = treenode
	}
	println("deleting ", iter.key)

	if countChildren(prev) == 0 {
		prev.next[lastDigit] = nil
	}
	iter.value = ""
	return true
}

func traverse(iter *node, count func()) {

	count()
	if iter != nil {
		if iter.key != -1 {
			println(iter.key)
		}
		if iter.value != "" {
			println(iter.value)
		}
		for i := 0; i < 10; i++ {
			traverse(iter.next[i], count)
		}
	}
}

func main() {
	fmt.Println("vim-go")
	myTree := prefixTree{}
	myTree.insert(1234, "hello")
	myTree.insert(123, "hello")
	println(myTree.size)
	count := 0
	traverse(myTree.root, func() { count++ })
	myTree.remove(123)
	traverse(myTree.root, func() { count++ })
	println("count ", count)
}
