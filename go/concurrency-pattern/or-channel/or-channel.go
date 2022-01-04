package main

import "time"
import "fmt"

var or func(channels ...<-chan interface{}) <-chan interface{}

func main() {
	// or function will take n number of channels and if any of these channels
	// are closed/done this function will return
	or = func(channels ...<-chan interface{}) <-chan interface{} {
		switch len(channels) {
		case 0:
			return nil
		case 1:
			return channels[0]

		}

		orDone := make(chan interface{})
		go func() {
			defer close(orDone)
			switch len(channels) {
			case 2:
				select {
				case <-channels[0]:
				case <-channels[1]:
				}
			default:
				select {
				case <-channels[0]:
				case <-channels[1]:
				case <-channels[2]:
					// call to or function
				case <-or(append(channels[3:], orDone)...):
				}

			}
		}()
		return orDone
	}
	sig := func(after time.Duration) <-chan interface{} {
		c := make(chan interface{})
		go func() {
			defer close(c)
			time.Sleep(after)
		}()
		return c
	}

	start := time.Now()

	<-or(
		sig(2*time.Minute),
		sig(1*time.Minute),
		sig(30*time.Second),
		sig(10*time.Second),
		sig(5*time.Second),
	)

	fmt.Printf("done after %v", time.Since(start))
}
