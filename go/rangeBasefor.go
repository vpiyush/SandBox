package main

import (
	"fmt"
	"os"
)

func main() {
	var s, sep string
	sep = " "
	for _, val := range os.Args[1:] {
		s += val
		s += sep
	}
	fmt.Println(s)
}
