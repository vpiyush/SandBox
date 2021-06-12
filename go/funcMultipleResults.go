package main

import "fmt"

func add(x, y int) (int, int) {
	return (x + y), x
}

func main() {
	a, b := add(12, 14)
	fmt.Println(a, b)
}
