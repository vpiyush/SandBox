package main

import "fmt"

func main() {
	generator := func(done <-chan interface{}, integers ...int) <-chan int {

		intStream := make(chan int)
		go func() {
			defer close(intStream)
			for _, no := range integers {
				select {
				case <-done:
					return
				case intStream <- no:
				}

			}
		}()
		return intStream

	}
	multiply := func(done <-chan interface{}, inStream <-chan int, multiplier int) <-chan int {
		mulStream := make(chan int)
		go func() {
			defer close(mulStream)
			for no := range inStream {
				select {
				case <-done:
					return
				case mulStream <- no * multiplier:
				}

			}
		}()
		return mulStream
	}

	add := func(done <-chan interface{}, inStream <-chan int, additive int) <-chan int {
		addStream := make(chan int)
		go func() {
			defer close(addStream)
			for no := range inStream {
				select {
				case <-done:
					return
				case addStream <- no + additive:
				}

			}
		}()
		return addStream
	}

	done := make(chan interface{})
	defer close(done)
	intStream := generator(done, 1, 3, 4, 5, 6, 7)
	pipeline := multiply(done, add(done, multiply(done, intStream, 2), 1), 2)
	for v := range pipeline {
		fmt.Println(v)
	}

}
