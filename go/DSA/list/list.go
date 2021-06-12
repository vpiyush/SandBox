package main

import "fmt"
import "container/list"

func main() {
	var intlist list.List
	intlist.PushBack(1)
	intlist.PushBack(2)
	intlist.PushBack(3)

	for element := intlist.Front(); element != nil; element = element.Next() {
		fmt.Println("vim-go ", element.Value.(int))
	}
}
