package main

import (
	"fmt"
	"sync"
)

var data int

var loader sync.Once

func loadData() {
	data++
}

func main() {

	for i := 0; i < 5; i++ {
		loader.Do(loadData)
	}
	fmt.Println("myData: ", data)

}
