package main

import (
	"fmt"
	"sync"
)

func getInputChannel() <-chan int {
	intStream := make(chan int)
	go func() {
		defer close(intStream)
		integers := []int{0, 1, 2, 3, 4, 5}
		for i := range integers {
			select {
			case intStream <- i:
			}
		}

	}()
	return intStream

}

func getSquareChannel(intStream <-chan int) <-chan int {
	squareStream := make(chan int)
	go func() {
		defer close(squareStream)
		for i := range intStream {
			select {
			case squareStream <- i * i:
			}
		}
	}()
	return squareStream
}

func merge(inputChannels ...<-chan int) <-chan int {
	var wg sync.WaitGroup
	merged := make(chan int, 100)

	multiplex := func(c <-chan int) {
		defer wg.Done()
		for sq := range c {
			select {
			case merged <- sq:
			}
		}
	}
	wg.Add(len(inputChannels))
	for _, sq := range inputChannels {
		multiplex(sq)
	}
	go func() {
		wg.Wait()
		close(merged)
	}()
	return merged

}
func main() {
	inputChannel := getInputChannel()

	sqChannel1 := getSquareChannel(inputChannel)
	sqChannel2 := getSquareChannel(inputChannel)

	mergedChannel := merge(sqChannel1, sqChannel2)

	sqSum := 0

	for val := range mergedChannel {
		sqSum += val
	}
	fmt.Println("Sqsum ", sqSum)
}
