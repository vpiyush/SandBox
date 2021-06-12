package main

import "fmt"
import "io"
import "log"
import "net"
import "os"

func main() {
	fmt.Println("vim-go")
	conn, err := net.Dial("tcp", "localhost:8080")
	if err != nil {
		log.Fatal("dial failed", err)
	}
	done := make(chan struct{})
	go func() {
		io.Copy(os.Stdout, conn)
		log.Println("done")
		done <- struct{}{}
	}()
	mustCopy(conn, os.Stdin)
	conn.Close()
	<-done // just wait on done channel, discard the recieve. we are not sending anythign anyway
}

func mustCopy(dst io.Writer, src io.Reader) {
	io.Copy(dst, src)
}
