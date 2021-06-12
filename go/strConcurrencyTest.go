package main

import "fmt"
import "strconv"
import "time"

type MyStr struct {
	str string
}

func printStr(myStr *MyStr) {
	for {
		fmt.Println("my Str ", myStr.str)
	}
}
func changeStr(myStr *MyStr) {
	i := 5323232432
	temp := "hellofdakshfkdsahfkdshafkhdskfhasdhfakshfdkshfdskfh"
	fmt.Println("running main")
	for count := i; count < 9932323243; count++ {
		myStr.str = temp + strconv.Itoa(count)
	}
	fmt.Println("It's Over ")
}
func main() {
	var myStr MyStr
	myStr.str = "initial"
	go printStr(&myStr)
	go changeStr(&myStr)
	time.Sleep(60 * time.Second)
	fmt.Println("It's Over in main")
}
