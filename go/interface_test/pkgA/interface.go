package main

import "fmt"

type animal interface {
	eat()
}

type dog struct {
}

func foodie() {
	var an animal
	an = dog{}
	an.eat()
}

func main() {

	foodie()
}
