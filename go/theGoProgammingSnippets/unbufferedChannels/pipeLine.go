package main

import (
	"fmt"
)

func main() {
	naturals := make(chan int)
	squarers := make(chan int)

	go func() {
		for x := 0; x < 10; x++ {
			naturals <- x
		}
		//	close(naturals)
	}()
	go func() {
		for {
			x, ok := <-naturals
			if !ok { // check if naturals channel is drained completely
				break
			}
			squarers <- x * x
		}
		close(squarers)
	}()

	//Alternate
	/*	go func() {
		for x := range naturals {
			squarers <- x * x
		}
		close(squarers)
	}()*/
	for x := range squarers {
		fmt.Println(x)
	}
}
