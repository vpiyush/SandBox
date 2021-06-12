package main

import (
	"fmt"
)

func naturalGen(out chan<- int) {
	for x := 0; x < 10; x++ {
		out <- x
	}
	close(out)
}
func squarerGen(out chan<- int, in <-chan int) {
	for {
		x, ok := <-in
		if !ok { // check if naturals channel is drained completely
			break
		}
		out <- x * x
	}
	close(out)
}

func printer(in <-chan int) {
	for x := range in {
		fmt.Println(x)
	}
}
func main() {
	naturals := make(chan int)
	squarers := make(chan int)

	go naturalGen(naturals)
	go squarerGen(squarers, naturals)
	printer(squarers)
	//Alternate
	/*	go func() {
		for x := range naturals {
			squarers <- x * x
		}
		close(squarers)
	}()*/
}
