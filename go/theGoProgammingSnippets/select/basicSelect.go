package main

import "fmt"

func main() {
	fmt.Println("vim-go")
	ch := make(chan int, 1)
	for i := 0; i < 10; i++ {
		select {
		case ch <- i:
		case x := <-ch:
			fmt.Println("x :", x)
		}
	}
}
