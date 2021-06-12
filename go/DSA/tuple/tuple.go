package main

import "fmt"

// the return values is notthing but a tuple,
// tuple is a finite list of sorted values
func powerSeries(a int) (int, int) {
	return a * a, a * a * a
}

func main() {
	square, cube := powerSeries(5)
	fmt.Println("vim-go: ", square, cube)
}
