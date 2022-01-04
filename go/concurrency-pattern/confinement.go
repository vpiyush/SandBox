package main

import "fmt"
import "sync"
import "bytes"

func main() {
	// to achieve confinement we need to limit the scope of write or read access to memory with in a function
	// and only allow one of the operation from outside
	printData := func(wg *sync.WaitGroup, data []byte) {
		defer wg.Done()

		var buff bytes.Buffer
		// read acccess to data is confined with in a function
		for _, d := range data {
			fmt.Fprintf(&buff, "%c", d)
		}
		fmt.Println(buff.String())
	}
	var wg sync.WaitGroup
	wg.Add(2)
	data := []byte("golang")
	// we already break the data and give to the print Data function
	// which eliminates the possibility of corrupting the data with in the function
	printData(&wg, data[:3])
	printData(&wg, data[3:])
	wg.Wait()
}
