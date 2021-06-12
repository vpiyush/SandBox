package main

import "fmt"

type dllNode struct {
	value interface{}
	prev  *dllNode
	next  *dllNode
}

type dll struct {
	head *dllNode
	tail *dllNode
}

func createNode(n int) *dllNode {
	var node dllNode
	node.value = n
	node.prev = nil
	node.next = nil
	return &node
}

func (d *dll) insertHead(dnode *dllNode) {
	dnode.prev = nil
	dnode.next = d.head
	d.head = dnode
}

func (d *dll) insertTail(dnode *dllNode) {
	dnode.prev = nil
	dnode.next = d.head
	d.head = dnode

}

func (d *dll) printDll() {
	node := d.head
	for node.next != nil {
		fmt.Println(node.value.(int))
		node = node.next
	}
	fmt.Println(node.value.(int))

}
func main() {
	var dlist dll

	dlist.insertHead(createNode(1))
	dlist.insertHead(createNode(2))
	dlist.printDll()

}
