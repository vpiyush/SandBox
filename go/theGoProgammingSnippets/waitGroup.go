package main

import (
	"fmt"
	"sync"
)

func worker(i int, wg *sync.WaitGroup) {
	defer wg.Done()
	fmt.Println("starting id:", i)
	fmt.Println("Done id:", i)
}

func main() {
	var wg sync.WaitGroup
	for i := 1; i < 10; i++ {
		wg.Add(1)
		go worker(i, &wg)
	}

	wg.Wait()
}
