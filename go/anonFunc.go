package main

import (
	"fmt"
)

func squareRoot(x int) func() int {
	return func() int {
		x++
		return x * x
	}
}

func main() {

	f := squareRoot(3)
	fmt.Println("f(3)", f())

}
