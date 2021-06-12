package main

import "os"
import "fmt"

func main() {
	fmt.Println("here is the args len", len(os.Args))
	fmt.Println("here is the args ", os.Args)
}
